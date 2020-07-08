
#  include <stdio.h>
#  include <stdlib.h>
#  include <stdarg.h>
#  include <string.h>
#  include <math.h>
#  include <time.h>
#  include <unistd.h>
#  include "headers/claire.h"
#  include "headers/scope.h"
#  include "parser.tab.h"
#  include "headers/eval.h"
#  include "headers/device.h"

char* PATH;

AST* newast(int nodetype, AST* left, AST* right){
    AST* nast = (AST *) malloc(sizeof(AST));
    if(nast != NULL){
        nast->nodetype = nodetype;
        nast->left = left;
        nast->right = right;
        return nast;
    }
    yyerror("Heap space is full");
    exit(1);
}

AST* newastscope(int nodetype, AST* left, AST* right, SYMBOL* symhash){
    AST* nast = (AST *) malloc(sizeof(AST));
    if(nast != NULL){
        nast->nodetype = nodetype;
        nast->left = left;
        nast->right = right;
        nast->symhash = (AST*) symhash;
        return nast;
    }
    yyerror("Heap space is full");
    exit(1);
}

AST* newfunc(SYMBOL* ref, AST* namelist, AST* instructions, AST* enddef){
    FUNCTION* f = ref->func;
    f->nodetype = FUNC;
    f->instructions = instructions;
    f->enddef = enddef;
    if(namelist != NULL){
        f->namelist = namelist;
    }
    return (AST*) f;
};

SYMBOL* newfuncref(SYMBOL* symbol){
    symbol->func = (FUNCTION*) malloc(sizeof(FUNCTION));
    if(symbol->func != NULL){
        symbol->fsymhash = (SYMBOL*) malloc(HEAPSIZE*sizeof(SYMBOL));
        return symbol;
    }
    yyerror("Heap space is full");
    exit(1);
}

AST* newflow(AST* exp, AST* stat, AST* els, SYMBOL* scope){
    FLOW* newl = (FLOW *) malloc(sizeof(FLOW));
    if(newl != NULL){
        newl->nodetype = QM;
        newl->exp = exp;
        newl->stat = stat;
        newl->els = els;
        newl->symhash = (AST*) scope;
        return (AST*) newl;
    }
    yyerror("Heap space is full");
    exit(1);
}

AST* newfloat(double d){
    LNUM* newl = (LNUM *) malloc(sizeof(LNUM));
    if(newl != NULL){
        newl->nodetype = NUMBER;
        newl->value = d;
        AST* a = (AST *) newl;
        return a;
    }
    yyerror("Heap space is full");
    exit(1);
}

AST* newstring(char* s){
    LSTRING* newl = (LSTRING *) malloc(sizeof(LSTRING));
    if(newl != NULL){
        newl->nodetype = STRING;
        newl->value = strdup(s);
        return (AST *) newl;
    }
    yyerror("Heap space is full");
    exit(1);
}

AST* newboolean(int b){
    LBOOLEAN* newl = (LBOOLEAN *) malloc(sizeof(LBOOLEAN));
    if(newl != NULL){
        newl->nodetype = BOOLEAN;
        if(b!=0) b = 1;
        newl->value = b;
        return (AST *) newl;
    }
    yyerror("Heap space is full");
    exit(1);
}

AST* newdevice(char* deviceid){
    LDEVICE* newl = (LDEVICE *) malloc(sizeof(LDEVICE));
    newl->nodetype = DEVICEID;
    if(newl != NULL){
        char* filename;
        //
        asprintf(&filename,"%ssensor/%s.sensor",PATH,deviceid);
        FILE* ptr = fopen(filename,"r");
        if(ptr){
            newl->filename = filename;
            newl->deviceid = strdup(++deviceid);
            readdev((AST*)newl);
            fclose(ptr);
            return (AST *) newl;
        }
        fclose(ptr);
        yyerror("Sensor doesn't exists");
        exit(1);
    }
    yyerror("Heap space is full");
    exit(1);
}

AST* newcollection(VARLIST* list){
    LCOLLECTION* newl = (LCOLLECTION *) malloc(sizeof(LCOLLECTION));
    if(newl != NULL){
        newl->nodetype = COLLECTION;
        newl->collectiontype = list->value->nodetype;
        VARLIST* p = list;
        int k = 0;
        while(p != NULL){
            if(p->value->nodetype != newl->collectiontype){
                yyerror("Types on a collection cannot be different");
                exit(1);
            }
            p = p->next;
            k++;
        }
        newl->size = k;
        newl->collection = list;
        return (AST *) newl;
    }
    yyerror("Heap space is full");
    exit(1);
}

VARLIST* newvarlist(AST* value, VARLIST* next){
    VARLIST* vl = (VARLIST*) malloc(sizeof(VARLIST));
    if(vl != NULL) {
        vl->nodetype = LIST;
        vl->value = value;
        vl->next = next;
        return vl;
    }
    yyerror("out of space");
    exit(0);
}

SYMLIST* newsymlist(SYMBOL* value, SYMLIST* next){
    SYMLIST* sl = (SYMLIST*) malloc(sizeof(SYMLIST));
    if(sl != NULL) {
        sl->nodetype = SYML;
        sl->value = value;
        sl->next = next;
        return sl;
    }
    yyerror("out of space");
    exit(0);
}

AST* newasgn(SYMREF* s, AST* v) {
    SYMASGN* newl = (SYMASGN*) malloc(sizeof(SYMASGN));
    if(newl != NULL) {
        newl->nodetype = ASSIGN;
        newl->ref = s;
        newl->assignment = v;
        return (AST*) newl;
    }
    yyerror("out of space");
    exit(1);
}

AST* newsymasgn(SYMBOL* s, AST* v) {
    SYMASGN* newl = (SYMASGN*) malloc(sizeof(SYMASGN));
    SYMREF* symref = newref(s,NULL);
    if(newl != NULL && symref != NULL) {
        newl->nodetype = ASSIGN;
        newl->ref = symref;
        newl->assignment = v;
        return (AST*) newl;
    }
    yyerror("out of space");
    exit(1);
}

SYMREF* newref(SYMBOL* s, AST* index){
    SYMREF* a = (SYMREF*) malloc(sizeof(SYMREF));
    if(a != NULL) {
        a->nodetype = IDENTIFIER;
        a->symbol = s;
        a->index = index;
        a->readingtype = 0;
        return a;
    }
    yyerror("out of space");
    exit(1);
}

AST* newbinfunc(AST* in, int func){
    BUILTIN* b = (BUILTIN*) malloc(sizeof(BUILTIN));
    if(b != NULL){
        b->nodetype = BULTIN;
        b->fname = func;
        b->input = in;
        return (AST*) b;
    }
    yyerror("out of space");
    exit(1);
}

int main(int argc, char* argv[]){
    char *user = getenv("USER");
    asprintf(&PATH,"/Users/%s/ClaireSDK/",user);
    scopestack[0] = symhash;
    FILE* input = fopen(argv[1],"r");
    setInput(input);
    yyparse();
    fflush(input);
    fclose(input);
    return 0;
}

void yyerror(char *s){
    fprintf(stderr, "error: %s\n", s);
}
