# Claire SDK
CLAIRE è un linguaggio di programmazione che ha lo scopo di interfacciarsi con un setup di device all’interno di un contesto che può essere, ad esempio, quello domotico, ed ha come ulteriore obiettivo essere di facile leggibilità e utilizzo da parte di utenti non particolarmente esperti in ambito di linguaggi di programmazione, da qui il nome CLAIRE per indicarne la chiarezza.
Per inizializzare Claire è sufficiente:
1. Scaricare il codice sorgente del compilatore:
    [Scarica compilatore](https://github.com/AndreaVaiuso/ClaireSDK.git)
2. Scaricare ed eseguire l'ambiente di sviluppo:
    [Download SDK](https://github.com/AndreaVaiuso/ClaireSDK/tree/master/Executable)

Per compilare il codice sorgente basterà portarsi nella directory /build ed avviare

`./compile`

in alternativa digitare

`gcc -o claire "claire.c" "lex.yy.c" parser.tab.c`

Per la documentazione completa:
https://github.com/AndreaVaiuso/ClaireSDK/blob/master/doc/index.html

