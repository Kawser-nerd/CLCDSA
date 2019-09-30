#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    char s[30],t[27]="abcdefghijklmnopqrstuvwxyz",u[27]="zyxwvutsrqponmlkjihgfedcba";
    scanf("%s",s);
    int count=0;
    bool letter[26]={};
    for (int i=0; i<strlen(t); i++){
        for (int j=0; j<strlen(s); j++){
            if (s[j]==t[i]){
                letter[i]=true;
                count++;
            }
        }
    }
    if (count!=26){
        printf("%s",s);
        for (int i=0; i<strlen(t); i++){
            if (letter[i]==false){
                printf("%c\n",t[i]);
                break;
            }
        }
    } else {
        if (strcmp(s,u)==0){
            printf("-1\n");
        } else {
            int last,prev=0;
            for (int i=0; i<strlen(s); i++){
                for (int j=0; j<strlen(t); j++){
                    if (s[strlen(s)-1-i]==t[j]){
                        last=j;
                    }
                }
                if (last<prev){
                    for (int k=0; k<strlen(s)-1-i; k++){
                        printf("%c",s[k]);
                    }
                    for (int k=last; k<strlen(t); k++){
                        if (letter[k]==false){
                            printf("%c\n",t[k]);
                            return 0;
                        }
                    }
                } else {
                    prev=last;
                    letter[last]=false;
                }
            }
        }
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^