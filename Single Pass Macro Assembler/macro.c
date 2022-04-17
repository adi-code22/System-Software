#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *f1, *f3,*f2, *f4, *f5;
    char la[20], mne[20], opnd[20], strt[20], name[20], mne1[20], opnd1[20];
    int pos = 0, len;

    f1 = fopen("macrot.txt", "r");
    f2 = fopen("namtab.txt", "w+");
    f3 = fopen("deftab.txt", "w+");
    
    f4 = fopen("argtab.txt", "w+");
    f5 = fopen("output.txt", "w+");
    fscanf(f1, "%s%s%s", la, mne, opnd);
    while(strcmp(mne, "END") != 0){
        if(strcmp(mne, "MACRO") == 0){
            fprintf(f2, "%s\n", la);
            fclose(f2);
            
            fprintf(f3, "%s\t%s\n",la, opnd);
            fclose(f3);
            
            
            fscanf(f1, "%s%s%s", la, mne, opnd);
            while(strcmp(mne, "MEND") != 0){
                if(opnd[0] == '&'){
                    pos++;
                    itoa(pos,strt,10);
                    strcpy(opnd, strcat("N", strt));
                    
                }
                fopen_s(&f3,"deftab.txt", "w+");
                fprintf(f3, "%s\t%s\n", mne,opnd);
                
                fscanf(f1, "%s%s%s", la, mne, opnd);
            }
            fprintf(f3, "%s", mne);

        }
        else{
            fscanf(f2, "%s", name);
            if(strcmp(name, mne) == 0){
                len = strlen(opnd);
                for(int i=0; i<len; i++){
                    if(opnd[i] != ','){
                        fprintf(f4, "%c", opnd[i]);
                    }
                    else{
                        fprintf(f4, "\n");
                    }
                }
                fseek(f3, SEEK_SET, 0);
                fseek(f4, SEEK_SET, 0);
                fscanf(f3, "%s%s", mne1, opnd1);
                fprintf(f5, "-\t%s\t%s\n", mne1, opnd);
                fscanf(f3, "%s%s", mne1, opnd1);
                while(strcmp(mne1, "MEND") != 0){
                    if(opnd[0] == '?'){
                        //pass
                    }
                    else{
                        fscanf(f5, "-\t%s\t%s", mne1, opnd1);
                    }
                    fscanf(f3, "%s%s", mne1, opnd1);
                }
                

            }
            else{
                fprintf(f5, "%s\t%s\t%s\n", la, mne, opnd);
            }
            
        }
        fscanf(f1, "%s%s%s", la, mne, opnd);
    }
    fscanf(f5, "%s\t%s\t%s\n", la, mne, opnd);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    return 0;
}