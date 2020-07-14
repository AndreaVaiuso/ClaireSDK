%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "headers/claire.h"
    #include "headers/printree.h"
    FILE *out;
%}

%define parse.error verbose

%union{
    char* symbolname;
    SYMBOL* symbol;
    SYMLIST* symlist;
    SYMREF* symref;
    VARLIST* varlist;
    AST* ast;
};

%token MIN PRINT BULTIN CMDLIST IFLIST ENDIF LIST COLON LOOP PROCEDURE UPDATEDEF ENDDIR SCHEDULE OUTERIF
%token OP CP END BREAK INCREASE DECREASE BY REPEAT RETURN INPUT OUTPUT FUNC FCALL
%token DOT COMMA SEMICOLON QM ASSIGN CONNECT COLLECTION DISPLAY SIZE SLEEP SYML UNDEF
%token EQUALS ADD SUB DIV MUL ABS LT GT GE LE NE OQ CQ OG CG AND OR CONCAT

%token <symbolname> IDENTIFIER
%token <symbol> FIDENTIFIER DO IF ELSE UPDATE WHILE
%token <ast> DEVICEID
%token <ast> BOOLEAN
%token <ast> NUMBER
%token <ast> STRING

%type <varlist> varlist
%type <symlist> namelist
%type <ast> operation booleanop expression assign enddef functioncall
%type <ast> statement codeblock updatedef loopconstruct functionconstruct
%type <ast> conditionalconstruct conditionallist conditionalstat conditionalouterstat
%type <symref> refvar term 

%nonassoc CMP
%right EQUALS
%left OR
%left AND
%left ADD SUB
%left MUL DIV
%left BY
%nonassoc MINUS

%%
//PRODUZIONI
root: codeblock updatedef {
    if($1 != NULL){
        eval($1);
    }
    eval($2);
    }
;

codeblock: { $$ = NULL; }
| codeblock statement SEMICOLON { 
    if($1 == NULL){
        $$ = $2;
    } else $$ = newast(CMDLIST,$1,$2);
    }
;

functionconstruct: FIDENTIFIER OP namelist CP ASSIGN codeblock END { 
    $$ = newfunc($1,(AST*)$3,$6,NULL); prevscope(); }
| FIDENTIFIER OP CP ASSIGN codeblock END { $$ = newfunc($1,NULL,$5,NULL); prevscope(); }
;

statement: conditionalconstruct { $$ = $1; }
| conditionalouterstat END { $$ = newflow(NULL,$1,NULL,NULL); }
| conditionalouterstat ELSE codeblock END { $$ = newflow(NULL,$1,$3,$2); }
| loopconstruct { $$ = $1; }
| expression { $$ = $1; }
| functionconstruct { $$ = $1; }
;

conditionalconstruct: expression QM conditionallist END { $$ = newflow($1,$3,NULL,NULL); }
| expression QM conditionallist ELSE codeblock END { $$ = newflow($1,$3,$5,$4);   prevscope();  }
;

conditionallist: conditionalstat  { $$ = newast(IFLIST,$1,NULL); }
| conditionalstat conditionallist  { $$ = newast(IFLIST,$1,$2); }
;

conditionalstat: IF expression COMMA codeblock ENDIF SEMICOLON {
    $$ = newastscope(IF,$2,$4,$1); 
    prevscope();
    }
;

conditionalouterstat: IF booleanop COMMA codeblock {
    $$ = newastscope(IF,$2,$4,$1); 
    prevscope();
    }
;

loopconstruct: WHILE expression DO codeblock REPEAT { $$ = newastscope(WHILE,$2,$4,$3); prevscope();}
| DO codeblock WHILE expression REPEAT { $$ = newastscope(DO,$4,$2,$1);  prevscope(); }
;

updatedef: UPDATE ASSIGN codeblock enddef SEMICOLON {$$ = newastscope(UPDATEDEF,$3,$4,$1); prevscope();}
;

enddef: REPEAT { $$ = newast(REPEAT,NULL,NULL);}
| REPEAT operation { $$ = newast(REPEAT,$2,NULL); }
| REPEAT operation COMMA operation { $$ = newast(REPEAT,$2,$4); }
| END { $$ = newast(END,NULL,NULL); }
;

assign: term ASSIGN expression { $$ = newasgn($1,$3); }
| CONNECT IDENTIFIER DEVICEID { $$ = newsymasgn(findsymbol($2),$3); }
| COLLECTION IDENTIFIER ASSIGN OG varlist CG { $$ = newsymasgn(findsymbol($2),(AST*)$5); }
;

expression: assign {$$ = $1; }
| SLEEP OP operation CP { $$ = newbinfunc($3,2); }
| PRINT OP expression CP { $$ = newbinfunc($3,0); }
| operation { $$ = $1; }
| booleanop { $$ = $1; }
| BREAK { $$ = newast(BREAK,NULL,NULL); }
| RETURN operation { $$ = newast(RETURN,$2,NULL); }
| RETURN booleanop { $$ = newast(RETURN,$2,NULL); }
;

booleanop: BOOLEAN { $$ = $1; }
| OP booleanop CP { $$ = $2; }
| booleanop AND booleanop { $$ = newast(AND,$1,$3); };
| booleanop OR booleanop { $$ = newast(OR,$1,$3); };
| operation EQUALS operation %prec CMP { $$ = newast(EQUALS,$1,$3); }
| operation NE operation %prec CMP { $$ = newast(NE,$1,$3); }
| operation LT operation %prec CMP { $$ = newast(LT,$1,$3); }
| operation GT operation %prec CMP { $$ = newast(GT,$1,$3); }
| operation GE operation %prec CMP { $$ = newast(GE,$1,$3); }
| operation LE operation %prec CMP { $$ = newast(LE,$1,$3); }

;

operation: term { $$ = (AST*) $1; }
| STRING { $$ = $1; }
| NUMBER { $$ = $1; }
| SIZE OP term CP { $$ = newbinfunc((AST*)$3,1); }
| functioncall { $$ = $1; }
| operation ADD operation { $$ = newast(ADD,$1,$3); }
| operation SUB operation { $$ = newast(SUB,$1,$3); }
| operation DIV operation { $$ = newast(DIV,$1,$3); }
| operation MUL operation { $$ = newast(MUL,$1,$3); }
| INCREASE term BY operation { $$ = newast(INCREASE,(AST*)$2,$4); }
| DECREASE term BY operation { $$ = newast(DECREASE,(AST*)$2,$4); }
| SUB operation %prec MINUS { $$ = newast(MIN,$2,NULL); }
| ABS operation ABS { $$ = newast(ABS,$2,NULL); }
| OP operation CP { $$ = $2; }
;

functioncall: IDENTIFIER OP varlist CP {
    char* id = strdup($1);
    strcat(id,"()");
    $$ = newast(FCALL,(AST*)findsymbol(id),(AST*)$3); 
    }
| IDENTIFIER OP CP {
    char* id = strdup($1);
    strcat(id,"()");
    $$ = newast(FCALL,(AST*)findsymbol(id),NULL); 
    }
;

varlist: expression { $$ = newvarlist($1,NULL); }
| expression COMMA varlist { $$ = newvarlist($1,$3); }
;

namelist: IDENTIFIER { $$ = newsymlist(lookup($1),NULL); }
| IDENTIFIER COMMA namelist { $$ = newsymlist(lookup($1),$3); }
;

term: refvar { $$ = $1; }
| refvar DOT INPUT { $1->readingtype = -1; $$ = $1; }
| refvar DOT OUTPUT { $1->readingtype = 1; $$ = $1; }
;

refvar: IDENTIFIER {
    $$ = newref(findsymbol($1),NULL); 
    }
| IDENTIFIER OQ operation CQ { 
    $$ = newref(findsymbol($1),$3); 
    }
;


%%