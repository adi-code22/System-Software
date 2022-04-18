#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(){
    FILE *f1, *f2, *f3, *f4;
    char str1[20], str2[20], str3[20], opcode[20], value[20];
    int start1, n;
    f1 = fopen("inputprgm.txt", "r");
    f2 = fopen("symtab.txt", "w");
    f3 = fopen("object_code.txt", "w");

    struct node{
        char symb[100];
        int opvalue;
        int symvalue;
        struct node *next;

    } *start=NULL, *prev=NULL, *ptr=NULL;

    fscanf(f1, "%s%s%s", str1, str2, str3);
    if(strcmp(str2, "START") == 0){
        start1 = atoi(str3);
        n = start1;
    }
    while(strcmp(str2, "END") != 0){
        fscanf(f1, "%s%s%s", str1, str2, str3);
        if(strcmp(str2, "RESW")!= 0 && strcmp(str2, "RESB")!= 0 && strcmp(str2, "BYTE")!= 0 && strcmp(str2, "WORD")!= 0 && strcmp(str2, "END")!= 0){
            f4 = fopen("optab.txt", "r");
            if(start == NULL){
                start = (struct node*)malloc(sizeof(struct node));
                strcpy(start->symb, str3);

                while(fscanf(f4, "%s%s", opcode, value) != EOF){
                    if(strcmp(str2, opcode) == 0){
                        start->opvalue = atoi(value);
                        break;
                    }
                }
                start->symvalue = start1;
                start->next = NULL;

            }
            else{

                ptr = start;
                while(ptr->next != NULL){
                    ptr = ptr->next;
                }
                struct node *temp = (struct node*)malloc(sizeof(struct node));
                ptr->next = temp;
                strcpy(temp->symb, str3);

                while(fscanf(f4, "%s%s", opcode, value) != EOF){
                    if(strcmp(str2, opcode) == 0){
                        temp->opvalue = atoi(value);
                        break;
                    }
                }
                temp->symvalue = start1;
                temp->next = NULL;

            }
            fclose(f4);
        }
        if(strcmp("**", str1) != 0){
            fprintf(f2, "%s %d\n", str1, start1);
            ptr = start;
            while(ptr != NULL){
                if(strcmp(ptr->symb, str1) == 0){
                    ptr->symvalue = start1;
                    break;
                }
                ptr = ptr->next;
            }
        }
        if(strcmp(str2, "RESW")==0){
            start1 += (3 * atoi(str3));
        }
        else if(strcmp(str2, "RESB")==0){
            start1 += atoi(str3);
        }
        else{
            start1 += 3;
        }

    }
    fclose(f1);
    fclose(f2);
    ptr = start;
    while(ptr != NULL){
        
            fprintf(f3, "%02d%d\n", ptr->opvalue, ptr->symvalue);
            ptr = ptr->next;
    }
    fclose(f3);
    return 0;

}