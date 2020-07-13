SYMBOL* scopestack[SCOPESIZE];
int stackindex = 0;
int scopelimit = 0;

static unsigned hashf(char *sym){
    unsigned int hash = 0;
    unsigned c;
    while(c = *sym++) hash = hash*9 ^ c;
    return hash;
}

void prevscope(){
    stackindex--;
    if(stackindex < 0){
        stackindex = 0;
    }
}


SYMBOL* newscope(){
    return (SYMBOL*) malloc(HEAPSIZE*sizeof(SYMBOL));
}

void nextscope(SYMBOL* newsymash){
    stackindex++;
    scopestack[stackindex] = newsymash;
}

SYMBOL* lookup(char* name){
    SYMBOL* sym = &scopestack[stackindex][hashf(name)%HEAPSIZE];
    int count = HEAPSIZE;
    while(--count >= 0){
        if(sym->name != NULL && strcmp(sym->name, name) == 0) return sym;
        if(sym->name == NULL){
            sym->name = strdup(name);
            sym->value = newfloat(0.0);
            sym->func = NULL;
            sym->syms = NULL;
            sym->fsymhash = NULL;
            return sym;
        }
        if(++sym >= scopestack[stackindex]+HEAPSIZE) sym = scopestack[stackindex];
    }
    yyerror("Variable's symbol table overflow");
    exit(1);
}

SYMBOL* glookup(char* name, int currentindex){
    if(lookupverif(name)){
        SYMBOL* s = lookup(name);
        stackindex = currentindex;
        return s;
    } else {
        if(stackindex > scopelimit + 1){
            prevscope();
            return glookup(name,currentindex);
        } else {
            stackindex = 0;
            if(lookupverif(name)){
                SYMBOL* sym = lookup(name);
                stackindex = currentindex;
                return sym;
            } else {
                stackindex = currentindex;
                return lookup(name);
            }
        }
    }
}

int lookupverif(char* name){
    SYMBOL* sym = &scopestack[stackindex][hashf(name)%HEAPSIZE];
    int count = HEAPSIZE;
    while(--count >= 0){
        if(sym->name != NULL && strcmp(sym->name, name) == 0) return 1;
        if(sym->name == NULL) return 0;
        if(++sym >= scopestack[stackindex]+HEAPSIZE) sym = scopestack[stackindex];
    }
    yyerror("Variable's symbol table overflow");
    exit(1);
}

SYMBOL* findsymbol(char* text){
    return glookup(text,stackindex);
}

//Utility
void printcurrentsymhash(){
    printf("Print symhash:\n");
    for(int i = 0; i<HEAPSIZE; i++){
        if(scopestack[stackindex][i].name != NULL ){
            printf(" - %s -",scopestack[stackindex][i].name);
        }
    }
    printf("\n");
}




