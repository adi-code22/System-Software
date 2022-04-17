#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    FILE *f1, *f2;
    char input[20], label[20];
    int length=0, l, addr, taddr, start, end;
    f1 = fopen("abs.txt", "r");
    f2 = fopen("output.txt", "w");

    fscanf(f1, "%s", input);
    while(strcmp(input, "E") != 0){
        if(strcmp(input, "H") == 0){
            fscanf(f1, "%s%x%x%s", label, start, end, input);
            
        }
    }

    


}