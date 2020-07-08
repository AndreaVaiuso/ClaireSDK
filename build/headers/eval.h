int refreshrate = 50*1000;

void tfree(AST* ast){
    if(ast == NULL) return;
    tfree(ast->left);
    tfree(ast->right);
    free(ast);
}

AST* eval(AST* in){
    AST* retrvalue = (AST*) malloc(sizeof(AST));
    switch(in->nodetype){
        /*/////////////////////////LEAVES/////////////////////////////*/
        //Queste sono le foglie del nostro albero, le quali si limitano a ritornare il proprio valore
        case NUMBER: {retrvalue = in; break;}
        case STRING: {retrvalue = in; break;}
        case BOOLEAN: {retrvalue = in; break;}
        case DEVICEID: {retrvalue = in; break;}
        case BREAK: { retrvalue = in; break;}
        case RETURN: { retrvalue = in; break;}
        case LIST: { retrvalue = in; break;}
        case FUNC: { retrvalue = in; break; }
        case UNDEF: { retrvalue = in; break; }
        /*/////////////////////////IDENTIFIER/////////////////////////////*/
        //Questa rappresenta la gestione degli identificatori
        case IDENTIFIER: {
            SYMREF* ptr = (SYMREF*) in;
            //Is not an array
            if(ptr->index==NULL){
                //We want input or output
                if(ptr->readingtype != 0){
                    if(ptr->symbol->value->nodetype != DEVICEID){
                        yyerror("This is not a device");
                        exit(1);
                    }
                    updatedevice(ptr);
                    LDEVICE* dev = (LDEVICE*) ptr->symbol->value;
                    if(ptr->readingtype == 1) {
                        retrvalue = dev->output;
                    }
                    else {
                        retrvalue = dev->input;
                    }
                    //Is a simple variable
                } else {
                    updatedevice(ptr);
                    retrvalue = ptr->symbol->value;
                }
                //Is a vector
            } else {
                if(ptr->symbol->value->nodetype != COLLECTION){
                    yyerror("The element is not a collection");
                    exit(1);
                }
                
                LCOLLECTION* coll = (LCOLLECTION*) ptr->symbol->value;
                
                LNUM* ind = (LNUM*) eval(ptr->index);
                int i = ((int) ind->value);
                VARLIST* valptr = coll->collection;
                
                for(int j=0;j<i;j++){
                    if(valptr == NULL){
                        yyerror("Collection index out of bounds");
                        exit(1);
                    }
                    valptr = valptr->next;
                }
                return valptr->value;
            }
            break;
        }
        /*/////////////////////////ASSIGNMENT/////////////////////////////*/
        //Questa rappresenta la gestione degli assegnamenti
        case ASSIGN: {
            SYMASGN* ptr = (SYMASGN*) in;
            AST* assign = eval(ptr->assignment);
            SYMBOL* symbol = (SYMBOL*) ptr->ref->symbol;
            AST* val = symbol->value;
            int rightType = assign->nodetype;
            if(ptr->ref->index==NULL){
                //We want input or output
                if(ptr->ref->readingtype != 0){
                    if(val->nodetype != DEVICEID){
                        yyerror("This is not a device");
                        exit(1);
                    }
                    LDEVICE* dev = (LDEVICE*) val;
                    //CHECK TYPE COMPATIBILITY (Conflicting types)
                    if(dev->inputType==1 || dev->inputType==0){
                        if(assign->nodetype == NUMBER){
                            LNUM* num = (LNUM*) assign;
                            //Output case
                            if(ptr->ref->readingtype == 1){
                                dev->output = assign;
                                retrvalue = (AST*) dev->output;
                                //Input case
                            } else {
                                dev->input = assign;
                                retrvalue = (AST*) dev->input;
                            }
                            writedev(dev);
                            return retrvalue;
                        } else {
                            yyerror("You can use only number as input/output for this device");
                            exit(1);
                        }
                    } else {  //STRING DEVICE CASE
                        if(assign->nodetype == STRING){
                            //Output case
                            if(ptr->ref->readingtype == 1){
                                dev->output = assign;
                                retrvalue =  (AST*) dev->output;
                                //Input case
                            } else {
                                dev->input = assign;
                                retrvalue = (AST*) dev->input;
                            }
                            writedev(dev);
                            return retrvalue;
                        } else {
                            yyerror("You can use only strings as input/output for this device");
                            exit(1);
                        }
                    }
                    //Is a simple variable
                }
                //Is inside a vector
            } else {

                if(val->nodetype != COLLECTION){
                    yyerror("The element is not a collection");
                    exit(1);
                }
                LCOLLECTION* coll = (LCOLLECTION*) val;
                
                LNUM* ind = (LNUM*) eval(ptr->ref->index);
                int i = ((int) ind->value);
                VARLIST* valptr = coll->collection;
                
                for(int j=0;j<i;j++){
                    if(valptr == NULL){
                        yyerror("Collection index out of bounds");
                        exit(1);
                    }
                    valptr = valptr->next;
                }
                if(valptr->value->nodetype == assign->nodetype){
                    valptr->value = assign;
                    return valptr->value;
                } else {
                    yyerror("Conflicting types for collection");
                    exit(1);
                }
            }
            if(assign->nodetype == LIST){
                AST* coll = newcollection((VARLIST*)assign);
                (findsymbol(symbol->name))->value = coll;
                retrvalue = coll;
            } else {
                (findsymbol(symbol->name))->value = assign;
                retrvalue = assign;
            }
            break;
        }
            
            /*/////////////////////////OPERATIONS/////////////////////////////*/
        case ADD: {
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newfloat((nl->value)+(nr->value));
            } else if(l->nodetype == STRING && r->nodetype == STRING){
                LSTRING* nl = (LSTRING*) l;
                LSTRING* nr = (LSTRING*) r;
                char* str1 = strdup(nl->value);
                char* str2 = strdup(nr->value);
                retrvalue = newstring(strcat(str1,str2));
            } else if(l->nodetype == NUMBER && r->nodetype == STRING){
                LNUM* nl = (LNUM*) l;
                LSTRING* nr = (LSTRING*) r;
                char* buf;
                asprintf(&buf,"%g",nl->value);
                char* str2 = strdup(nr->value);
                retrvalue = newstring(strcat(buf,str2));
            } else if(l->nodetype == STRING && r->nodetype == NUMBER){
                LSTRING* nl = (LSTRING*) l;
                LNUM* nr = (LNUM*) r;
                char* buf;
                asprintf(&buf,"%g",nr->value);
                char* str1 = strdup(nl->value);
                retrvalue = newstring(strcat(str1,buf));
            } else {yyerror("Operation not allowed");exit(1);}
            break;
        }
        case SUB: {
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newfloat((nl->value)-(nr->value));
            } else {yyerror("Operation not allowed");exit(1);}
            break;
        }
        case MUL: {
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newfloat((nl->value)*(nr->value));
            } else {yyerror("Operation not allowed");exit(1);}
            break;
        }
        case DIV: {
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newfloat((nl->value)/(nr->value));
            } else {yyerror("Operation not allowed");exit(1);}
            break;
        }
        case INCREASE: {
            SYMREF* ref = (SYMREF*) in->left;
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newfloat((nl->value)+(nr->value));
            } else {yyerror("Operation not allowed");exit(1);}
            ref->symbol->value = retrvalue;
            break;
        }
        case DECREASE: {
            SYMREF* ref = (SYMREF*) in->left;
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newfloat((nl->value)-(nr->value));
            } else {yyerror("Operation not allowed");exit(1);}
            ref->symbol->value = retrvalue;
            break;
        }
        case ABS: {
            AST* l = eval(in->left);
            if(l->nodetype == NUMBER ){
                LNUM* nl = (LNUM*) l;
                retrvalue = newfloat(fabs(nl->value));
            } else {yyerror("Operation not allowed");exit(1);}
            break;
        }
        case MIN: {
            AST* l = eval(in->left);
            if(l->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                retrvalue = newfloat(-(nl->value));
            } else {yyerror("Operation not allowed");exit(1);}
            break;
        }
        case AND: {
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == BOOLEAN && r->nodetype == BOOLEAN){
                LBOOLEAN* nl = (LBOOLEAN*) l;
                LBOOLEAN* nr = (LBOOLEAN*) r;
                retrvalue = newboolean((nl->value) && (nr->value));
            } else if(l->nodetype == NUMBER && r->nodetype == BOOLEAN){
                LNUM* nl = (LNUM*) l;
                LBOOLEAN* nr = (LBOOLEAN*) r;
                retrvalue = newboolean((nl->value) && (nr->value));
            } else if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newboolean((nl->value) && (nr->value));
            } else if(l->nodetype == BOOLEAN && r->nodetype == NUMBER){
                LBOOLEAN* nl = (LBOOLEAN*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newboolean((nl->value) && (nr->value));
            }
            else {yyerror("Operation not allowed");exit(1);}
            break;
        }
        case OR: {
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == BOOLEAN && r->nodetype == BOOLEAN){
                LBOOLEAN* nl = (LBOOLEAN*) l;
                LBOOLEAN* nr = (LBOOLEAN*) r;
                retrvalue = newboolean((nl->value) || (nr->value));
            } else if(l->nodetype == NUMBER && r->nodetype == BOOLEAN){
                LNUM* nl = (LNUM*) l;
                LBOOLEAN* nr = (LBOOLEAN*) r;
                retrvalue = newboolean((nl->value) || (nr->value));
            } else if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newboolean((nl->value) || (nr->value));
            } else if(l->nodetype == BOOLEAN && r->nodetype == NUMBER){
                LBOOLEAN* nl = (LBOOLEAN*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newboolean((nl->value) || (nr->value));
            } else {yyerror("Operation not allowed");exit(1);}
            break;
        }
        case EQUALS: {
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newboolean((nl->value) == (nr->value));
            } else if(l->nodetype == STRING && r->nodetype == STRING){
                LSTRING* nl = (LSTRING*) l;
                LSTRING* nr = (LSTRING*) r;
                if(strcmp(nl->value,nr->value)==0){
                    retrvalue = newboolean(1);
                } else retrvalue = newboolean(0);
            } else if(l->nodetype == BOOLEAN && r->nodetype == BOOLEAN){
                LBOOLEAN* nl = (LBOOLEAN*) l;
                LBOOLEAN* nr = (LBOOLEAN*) r;
                retrvalue = newboolean((nl->value) == (nr->value));
            }
            else {retrvalue = newboolean(0);}
            break;
        }
        case NE: {
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newboolean((nl->value) != (nr->value));
            } else if(l->nodetype == STRING && r->nodetype != STRING){
                LSTRING* nl = (LSTRING*) l;
                LSTRING* nr = (LSTRING*) r;
                if(strcmp(nl->value,nr->value)==0){
                    retrvalue = newboolean(0);
                } else retrvalue = newboolean(1);
            } else if(l->nodetype == BOOLEAN && r->nodetype != BOOLEAN){
                LBOOLEAN* nl = (LBOOLEAN*) l;
                LBOOLEAN* nr = (LBOOLEAN*) r;
                retrvalue = newboolean((nl->value) != (nr->value));
            }
            else retrvalue = newboolean(1);
            break;
        }
        case LT: {
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newboolean((nl->value) < (nr->value));
            } else {yyerror("Operation not allowed");exit(1);}
            break;
        }
        case GT: {
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newboolean((nl->value) > (nr->value));
            } else {yyerror("Operation not allowed");exit(1);}
            break;
        }
        case GE: {
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newboolean((nl->value) >= (nr->value));
            } else {yyerror("Operation not allowed");exit(1);}
            break;
        }
        case LE: {
            AST* l = eval(in->left);
            AST* r = eval(in->right);
            if(l->nodetype == NUMBER && r->nodetype == NUMBER){
                LNUM* nl = (LNUM*) l;
                LNUM* nr = (LNUM*) r;
                retrvalue = newboolean((nl->value) <= (nr->value));
            } else {yyerror("Operation not allowed");exit(1);}
            break;
            break;
        }
            /*/////////////////////////FUNCTIONS/////////////////////////////*/
        case BULTIN: {
            BUILTIN* b = (BUILTIN*) in;
            if(b->fname == 2){
                AST* v = eval(b->input);
                if(v->nodetype != NUMBER){
                    yyerror("You must use numeric values");
                }
                int sl = (int) (((LNUM*) v)->value*1000000);
                usleep(sl);
                return v;
            }
            AST* v = eval(b->input);
            retrvalue = v;
            switch(v->nodetype){
                case NUMBER: {
                    if(b->fname == 0){
                        printf(">>%g\n",((LNUM*)v)->value);
                    }
                    if(b->fname == 1){
                        return newfloat(1.0);
                    }
                    break;
                }
                case STRING: {
                    if(b->fname == 0){
                        printf(">>%s\n",((LSTRING*)v)->value);
                    }
                    if(b->fname == 1){
                        return newfloat(strlen(((LSTRING*)v)->value));
                    }
                    break;
                }
                case BOOLEAN: {
                    if(b->fname == 0){
                        LBOOLEAN* bl = (LBOOLEAN*) v;
                        if(bl->value == 1) printf(">>true\n");
                        else printf(">>false\n");
                    }
                    if(b->fname == 1){
                        return newfloat(1.0);
                    }
                    break;
                }
                case DEVICEID: {
                    if(b->fname == 0){
                        printf(">>%s\n",((LDEVICE*)v)->deviceid);
                    }
                    if(b->fname == 1){
                        return newfloat(1.0);
                    }
                    break;
                }
                case COLLECTION: {
                    if(b->fname == 0){
                        LCOLLECTION* c = (LCOLLECTION*) v;
                        VARLIST* ptr = c->collection;
                        do {
                            eval(newbinfunc(ptr->value,0));
                        } while((ptr = ptr->next) != NULL);
                    }
                    if(b->fname == 1){
                        LCOLLECTION* c = (LCOLLECTION*) v;
                        return newfloat((double) c->size);
                    }
                    break;
                }
                default: {
                    if(b->fname == 0){
                        yyerror("Printing wrong type");
                    } if(b->fname == 1){
                        return newfloat(0.0);
                    }
                    break;
                }
            }
            retrvalue = v;
            break;
        }
        case FCALL: {
            SYMBOL* s = (SYMBOL*) in->left;
            char* fname = s->name;
            s = findsymbol(fname);
            FUNCTION* f = s->func;
            nextscope(s->fsymhash);
            VARLIST* ptrdummy = (VARLIST*) in->right;
            SYMLIST* ptrsymlist = (SYMLIST*) f->namelist;
            
            if(ptrsymlist!=NULL){
                do {
                    if(ptrdummy == NULL){
                        yyerror("Too few arguments");
                        exit(1);
                    }
                    ptrsymlist->value->value = eval(ptrdummy->value);
                    ptrsymlist = ptrsymlist->next;
                    ptrdummy = ptrdummy->next;
                }while(ptrsymlist != NULL);
            }
            
             if(ptrdummy != NULL){
                yyerror("Too many arguments");
                exit(1);
            }
            if((retrvalue = eval(f->instructions))->nodetype == RETURN){
                prevscope();
                return retrvalue->left;
            }
            prevscope();
            retrvalue = newast(UNDEF,NULL,NULL);
            break;
        }
        case UPDATEDEF: {
            AST* enddef = in->right;
            if(enddef->nodetype == REPEAT){
                if(!enddef->left && !enddef->right){
                    int pid = fork();
                    if(pid != 0){
                        while(1){
                            nextscope((SYMBOL*) in->symhash);
                            AST* val = eval(in->left);
                            usleep(refreshrate);
                            if(val->nodetype == BREAK){
                                prevscope();
                                break;
                            }
                            prevscope();
                        }
                    }
                } else if(enddef->left){
                    AST* refrate = eval(enddef->left);
                    if(refrate->nodetype!=NUMBER){
                        yyerror("Refresh rate can only be a number");
                        exit(1);
                    }
                    int rr = (int) (((LNUM*) refrate)->value*1000000);
                    if(enddef->right){
                        AST* timerep = eval(enddef->right);
                        if(timerep->nodetype != NUMBER){
                            yyerror("Repeat time can only be a number");
                            exit(1);
                        }
                        int times = (int) ((LNUM*) timerep)->value;
                        int count = 0;
                        int pid = fork();
                        if(pid != 0){
                            while(count<times){
                                nextscope((SYMBOL*) in->symhash);
                                AST* val = eval(in->left);
                                usleep(rr);
                                count++;
                                if(val->nodetype == BREAK){
                                    prevscope();
                                    break;
                                }
                                prevscope();
                            }
                        }
                    } else {
                        int pid = fork();
                        if(pid != 0){
                            while(1){
                                nextscope((SYMBOL*) in->symhash);
                                AST* val = eval(in->left);
                                usleep(rr);
                                if(val->nodetype == BREAK){
                                    prevscope();
                                    break;
                                }
                                prevscope();
                            }
                        }
                    }
                }
            } else if (enddef->nodetype == END) {
                int pid = fork();
                if(pid != 0){
                    nextscope((SYMBOL*) in->symhash);
                    eval(in->left);
                    prevscope();
                }
            }
            break;
        }
        
            /*//////////////////////////FLOWS////////////////////////////*/
        case WHILE: {
            nextscope((SYMBOL*) in->symhash);
            AST* res = eval(in->left);
            if(res->nodetype == BOOLEAN){
                while(((LBOOLEAN*) res)->value != 0){
                    retrvalue = eval(in->right);
                    if(retrvalue->nodetype == BREAK){
                        break;
                    }
                    res = eval(in->left);
                }
            }
            if(res->nodetype == NUMBER){
                while(((LNUM*) res)->value){
                    retrvalue = eval(in->right);
                    if(retrvalue->nodetype == BREAK){
                        break;
                    }
                    res = eval(in->left);
                }
            }
            prevscope();
            break;
        }
        case DO: {
            nextscope((SYMBOL*) in->symhash);
            AST* res = eval(in->left);
            if(res->nodetype == BOOLEAN){
                do {
                    retrvalue = eval(in->right);
                    if(retrvalue->nodetype == BREAK){
                        break;
                    }
                    res = eval(in->left);
                    
                } while(((LBOOLEAN*) res)->value != 0);
            }
            if(res->nodetype == NUMBER){
                do {
                    retrvalue = eval(in->right);
                    if(retrvalue->nodetype == BREAK){
                        break;
                    }
                    res = eval(in->left);
                } while(((LNUM*) res)->value);
            }
            prevscope();
            break;
        }
        case QM: {
            FLOW* flow = (FLOW*) in;
            AST* ev = flow->stat;
            int doelse = 1;
            if(flow->exp){
                do {
                    AST* ifstat = ev->left;
                    if(((LBOOLEAN*) eval(newast(EQUALS,flow->exp,ifstat->left)))->value){
                        nextscope((SYMBOL*) ifstat->symhash);
                        retrvalue = eval(ifstat->right);
                        prevscope();
                        doelse = 0;
                    }
                    ev = ev->right;
                } while (ev != NULL);
            } else {
                if(((LBOOLEAN*) eval(ev->left))->value){
                    nextscope((SYMBOL*) ev->symhash);
                    retrvalue = eval(ev->right);
                    prevscope();
                    doelse = 0;
                }
            }
            if(doelse){
                if(flow->els != NULL) {
                    nextscope((SYMBOL*) flow->symhash);
                    retrvalue = eval(flow->els);
                    prevscope();
                }
            }
            break;
        }
        case CMDLIST: {
            AST* prec = eval(in->left);
            if(prec->nodetype == RETURN){
                return newast(RETURN,eval(prec->left),NULL);
            }
            if(prec->nodetype == BREAK){
                return newast(BREAK,NULL,NULL);
            }
            AST* last = eval(in->right);
            if(last->nodetype == RETURN){
                return newast(RETURN,eval(last->left),NULL);
            }
            if(last->nodetype == BREAK){
                return newast(BREAK,NULL,NULL);
            }
            return last;
        }
        default: {}
    }
    return retrvalue;
}


