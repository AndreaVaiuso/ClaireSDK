# Claire SDK
CLAIRE è un linguaggio di programmazione che ha lo scopo di interfacciarsi con un setup di device all’interno di un contesto che può essere, ad esempio, quello domotico, ed ha come ulteriore obiettivo essere di facile leggibilità e utilizzo da parte di utenti non particolarmente esperti in ambito di linguaggi di programmazione, da qui il nome CLAIRE per indicarne la chiarezza.
Per inizializzare Claire è sufficiente:
1. Scaricare il codice sorgente del compilatore:
    [Scarica compilatore](https://github.com/AndreaVaiuso/ClaireSDK.git)
2. Scaricare ed eseguire l'ambiente di sviluppo:
    [Download SDK](https://github.com/AndreaVaiuso/ClaireSDK/tree/master/Executable)
3. Copiare l'intero contenuto della cartella /build all'interno della directory /User/NOMEUTENTE/ClaireSDK/build
4. Copiare la cartella /doc all'interno della directory /User/NOMEUTENTE/ClaireSDK/
5. Per compilare il codice sorgente basterà portarsi nella directory /build e digitare in una finestra del terminale il comando:

    Su macOs:
    
    `gcc -o claire "claire.c" "lex.yy.c" "parser.tab.c"` 
    
    Su Linux:
    
    `gcc -D_GNU_SOURCE -o claire "claire.c" "lex.yy.c" "parser.tab.c"`  
    
    Attenzione: Per avviare l'applicazione ClaireSDK.app su macOs è necessario abilitare l'esecuzione di applicazioni di sviluppatori non identificati. Per fare ciò, dal terminale digitare ed eseguire il seguente comando: `sudo spctl --master-disable`

Per la documentazione completa:
https://github.com/AndreaVaiuso/ClaireSDK/blob/master/doc/index.html

