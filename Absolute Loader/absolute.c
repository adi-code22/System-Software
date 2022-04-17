#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

FILE *f1, *f2;
char input[20], label[20];
int length=0, l, addr=0, taddr, start, address, end, ptaddr=0, w=0, count=0, i=0;

void check(){
    count++;
    address++;
    taddr++;
    if(count == 4){
        fprintf(f2, " ");
        i++;
        if(i==4){
            fprintf(f2, "\n%x\t\t\t", taddr);
            i=0;
        }
        count = 0;
    }

}
int main(){

    
    f1 = fopen("abs.txt", "r");
    f2 = fopen("output.txt", "w+");

    fscanf(f1, "%s", input);
    fprintf(f2, "MEMORY ADDRESS\t\t\t\tCONTENTS\n");
    while(strcmp(input, "E") != 0){
        if(strcmp(input, "H") == 0){
            fscanf(f1, "%s%x%x%s", label, &start, &end, input);
            
            address = start;
        }
        else if(strcmp(input, "T") == 0){
            l = length;
            ptaddr = addr;
            fscanf(f1, "%x%x%s", &taddr, &length, input);
            addr = taddr;
            if(w == 0){
                ptaddr = address;
                w=1;
            }
            for(int k=0; k<(taddr - (ptaddr + l)); k++){
                address=address+1;
                fprintf(f2, "xx");
                count++;
                if(count == 4){
                    fprintf(f2, " ");
                    i++;
                    if(i==4){
                        fprintf(f2, "\n%x\t\t\t", address);
                        i=0;
                    }
                    count = 0;
                }
            }
            if(taddr == start){
                fprintf(f2, "\n%x\t\t\t", taddr);
            }
            fprintf(f2, "%c%c", input[0], input[1]);
            check();
            fprintf(f2, "%c%c", input[2], input[3]);
            check();
            fprintf(f2, "%c%c", input[4], input[5]);
            check();
            fscanf(f1, "%s", input);


        }
        else{
            fprintf(f2, "%c%c", input[0], input[1]);
            check();
            fprintf(f2, "%c%c", input[2], input[3]);
            check();
            fprintf(f2, "%c%c", input[4], input[5]);
            check();
            fscanf(f1, "%s", input);

        }
    }
    while( i != 4){
        fprintf(f2, "xx");
        count++;
        if(count == 4){
            fprintf(f2, " ");
            i++;
            count = 0;
        }
    }
    fclose(f1);
    fclose(f2);


    
    return 0;

}