#define HEAPSIZE 4096
#define SCOPESIZE 512
#define SMSEP "||"

typedef struct ast {
    int nodetype;
    struct ast* left;
    struct ast* right;
    struct ast* symhash;
} AST;

typedef struct num {
    int nodetype; //NUMBER
    double value;
} LNUM;

/*
typedef struct integer {
    int nodetype; //INTEGER
    int value;
} LINT;
*/
typedef struct string {
    int nodetype; //STRING
    char* value;
} LSTRING;

typedef struct builtin {
    int nodetype; //BULTIN
    int fname;
    AST* input;
} BUILTIN;

typedef struct boolean {
    int nodetype; //BOOLEAN
    int value;
} LBOOLEAN;

typedef struct device {
    int nodetype; //DEVICEID
    char* filename;
    int inputType; //If is 0, atoi input and output to numbers, 1 float, 2 STR
    char* deviceid;
    int turnedOn;
    AST* input;
    AST* output;
} LDEVICE;

typedef struct varlist {
    int nodetype; //LIST
    AST* value;
    struct varlist* next;
} VARLIST;

typedef struct collection {
    int nodetype; //COLLECTION
    int size;
    int collectiontype;
    VARLIST* collection;
} LCOLLECTION;

typedef struct function {
    int nodetype; //FUNCTION
    AST* namelist;
    AST* instructions;
    AST* enddef;
} FUNCTION;

typedef struct symbol {
    char *name;
    AST* value;
    FUNCTION* func;
    VARLIST *syms;
    struct symbol* fsymhash;
} SYMBOL;

typedef struct flow {
    int nodetype; //QM
    AST* exp;
    AST* stat;
    AST* els;
    AST* symhash;
} FLOW;

typedef struct symlist {
    int nodetype; //SYMLIST
    SYMBOL* value;
    struct symlist* next;
} SYMLIST;



/*
typedef struct funcref {
    int nodetype; //FIDENTIFIER
    SYMBOL* symbol;
} FUNCREF;
*/

typedef struct symref {
    int nodetype; //IDENTIFIER
    AST* index; //If is a vector
    int readingtype; //-1 input, 1 output
    SYMBOL* symbol;
} SYMREF;

typedef struct symasgn {
    int nodetype; //ASSIGN
    SYMREF *ref;
    AST *assignment;
} SYMASGN;

SYMBOL* currentsymhash;
SYMBOL symhash[HEAPSIZE];


void prevscope();
void nextscope(SYMBOL* newsymash);
SYMBOL* newscope();

SYMBOL* lookup(char* name);
int lookupverif(char* name);
SYMBOL* findsymbol(char* text);

AST* newast(int nodetype, AST* left, AST* right);
AST* newastscope(int nodetype, AST* left, AST* right, SYMBOL* symhash);
AST* newfunc(SYMBOL* ref, AST* namelist, AST* instructions, AST* enddef);
SYMBOL* newfuncref(SYMBOL* symbol);
AST* newflow(AST* exp, AST* stat, AST* els, SYMBOL* scope);
AST* newfloat(double d);
AST* newstring(char* s);
AST* newboolean(int b);
AST* newdevice(char* deviceid);
AST* newcollection(VARLIST* list);
VARLIST* newvarlist(AST* value, VARLIST* next);
SYMLIST* newsymlist(SYMBOL* value, SYMLIST* next);
SYMREF* newref(SYMBOL* s, AST* index);
AST* newasgn(SYMREF* s, AST* v);
AST* newsymasgn(SYMBOL* s, AST* v);
void readdev(AST* var);
void updatedevice(SYMREF* dev);
void writedev(LDEVICE* ptr);
//void tfree(AST* in);

AST* eval(AST* in);

AST* newbinfunc(AST* in, int func);

void printcurrentsymhash();


extern int yylineno; /* from lexer */
void yyerror(char *s);

void setInput(FILE* input);
