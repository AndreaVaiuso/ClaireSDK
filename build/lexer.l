%option noyywrap nodefault yylineno

%{
#include "headers/claire.h"
#include "parser.tab.h"
	
%}

%%

"(" return OP;
")" return CP;
"[" return OQ;
"]" return CQ;
"{" return OG;
"}" return CG;

\. return DOT;
"," return COMMA;
";" return SEMICOLON;
":" return COLON;
"?" return QM;
"=" return EQUALS;
"!=" return NE; 
"+" return ADD;
"-" return SUB;
"/" return DIV;
"*" return MUL;
"|" return ABS;
"<->" return CONCAT;
"<" return LT;
">" return GT;
">=" return GE;
"<=" return LE;

and return AND;
or return OR;
end return END;
do { 
    yylval.symbol = newscope();
    nextscope(yylval.symbol);
    return DO;
}
if {
    yylval.symbol = newscope();
    nextscope(yylval.symbol);
    return IF;
}
endif return ENDIF;
else {
    yylval.symbol = newscope();
    nextscope(yylval.symbol);
    return ELSE;
}
increase return INCREASE;
by return BY;
decrease return DECREASE;
repeat return REPEAT;
return return RETURN;
input return INPUT;
output return OUTPUT;
while return WHILE;

is return ASSIGN;
connect return CONNECT;
collection return COLLECTION;
update {
    yylval.symbol = newscope();
    nextscope(yylval.symbol);
    return UPDATE;
}
print return PRINT;
break return BREAK;
size return SIZE;
sleep return SLEEP;
schedule return SCHEDULE;

yes {
    yylval.ast = newboolean(1);
    return BOOLEAN;
}

no {
    yylval.ast = newboolean(0);
    return BOOLEAN;
}

"#"[A-Z0-9]+ {
    yylval.ast = newdevice(yytext);
    return DEVICEID;
}

function" "[a-zA-Z][a-zA-Z0-9_]* {
    strtok(strdup(yytext)," ");
    char* fname = strtok(NULL," ");
    strcat(fname,"()");
    SYMBOL* f = newfuncref(lookup(fname));
    FUNCTION* fun = (FUNCTION*) f->func;
    nextscope(f->fsymhash);
    yylval.symbol = f;
    return FIDENTIFIER;
}

[a-zA-Z][a-zA-Z0-9_]* {
    yylval.symbolname = strdup(yytext);
    return IDENTIFIER;
}

[0-9]+\.?[0-9]* {
    yylval.ast = newfloat(atof(yytext));
    return NUMBER;
}

\"[^\"]*\" {
    char delim[] = "\"";
    char* ptr = strtok(yytext,delim);
    yylval.ast = newstring(ptr);
    return STRING;
}

"//".*    {;}
[\t\n ]   {;}
.       {printf("Unrecognized character: %s\n",yytext);}

<<EOF>>     {yyterminate();}

%%

void setInput(FILE* input){
    yyin = input;
}

int testFn(const char *str){
    return (str && *str && str[strlen(str) - 1] == '(') ? 0 : 1;
}