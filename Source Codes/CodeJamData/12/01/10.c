//
//  main.c
//  num1
//
//  Created by Dingjie Wang on 4/13/12.
//  Copyright 2012 asu. All rights reserved.
//

#include <stdio.h>

int main ()
{
    FILE *in;
    FILE *out;
    in=fopen("/Users/dingjiewang/Desktop/coding/num1/A-small-attempt1.in", "r");
    out=fopen("/Users/dingjiewang/Desktop/coding/num1/out.txt", "w");
    int i, j, k;
    int cs;
    char dump;
    fscanf(in, "%d", &cs);
    char list[26];
    char code[100];
    list[0]='y';
    list[1]='h';
    list[2]='e';
    list[3]='s';
    list[4]='o';
    list[5]='c';
    list[6]='v';
    list[7]='x';
    list[8]='d';
    list[9]='u';
    list[10]='i';
    list[11]='g';
    list[12]='l';
    list[13]='b';
    list[14]='k';
    list[15]='r';
    list[16]='z';
    list[17]='t';
    list[18]='n';
    list[19]='w';
    list[20]='j';
    list[21]='p';
    list[22]='f';
    list[23]='m';
    list[24]='a';
    list[25]='q';
    fscanf(in, "%c", &dump);
    for(i=0;i<cs;i++){
        for(j=0;j<100;j++){
            code[j]='\0';
        }
        fgets(&code[0], 1024,in);
        fprintf(out, "Case #%d: ", i+1);
        for(j=0;code[j];j++){
            if(code[j]==' '){
                fprintf(out, " ");
            }
            else{
                if(code[j]!='\n'){
                fprintf(out, "%c", list[code[j]-'a']);
                }
            }
        }
        fprintf(out, "\n");
    }
    fclose(in);
    fclose(out);
}

