void updatedevice(SYMREF* dev){
    if(dev->symbol->value->nodetype==DEVICEID){
        readdev(dev->symbol->value);
    }
}

void readdev(AST* var){
    LDEVICE* ptr = (LDEVICE *) var;
    char buf[512];
    FILE* fp = fopen(ptr->filename,"r");
    if(fp!=NULL){
            if(fscanf(fp,"%s\n",buf)>0){
                char* str = strtok(buf,SMSEP);
                str = strtok(NULL,SMSEP);
                if(strcmp(str,"true")==0){
                    ptr->turnedOn = 1;
                } else ptr->turnedOn = 0;
                str = strtok(NULL,SMSEP);
                ptr->inputType = atoi(str);
                char* in = strtok(NULL,SMSEP);
                char* out = strtok(NULL,SMSEP);
                if(ptr->inputType == 2) {
                    ptr->input = newstring(in);
                    ptr->output = newstring(out);
                } else {
                    ptr->input = newfloat(atof(in));
                    ptr->output = newfloat(atof(out));
                }
        }
    }
    fclose(fp);
}

void writedev(LDEVICE* ptr){
    AST* in = ptr->input;
    AST* out = ptr->output;
    FILE* fp = fopen(ptr->filename,"w");
    if(fp!=NULL){
        char* to;
        if(ptr->turnedOn) to = "true";
        else to = "false";
        if(ptr->inputType == 0 || ptr->inputType == 1){
            int chk;
            if((chk = fprintf(fp,"%s%s%s%s%d%s%g%s%g",ptr->deviceid,SMSEP,to,SMSEP,ptr->inputType,SMSEP,((LNUM*)in)->value,SMSEP,((LNUM*)out)->value)) > 0)
                ;
        } else {
            int chk;
            if((chk = fprintf(fp,"%s%s%s%s%d%s%s%s%s",ptr->deviceid,SMSEP,to,SMSEP,ptr->inputType,SMSEP,((LSTRING*)in)->value,SMSEP,((LSTRING*)out)->value)) > 0);
        }
    }
    fclose(fp);
}
