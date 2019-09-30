#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    int n;
    scanf("%d",&n);
    char s[n][25],t[25],u[25];
    for (int i=0; i<n; i++){
        scanf("%s",t);
        for (int i=0; i<strlen(t); i++){
            strncpy(u+i,t+strlen(t)-i-1,1);
        }
        u[strlen(t)]='\0';
        strcpy(s[i],u);
    }
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            char tmp[25];
            if (strcmp(s[i],s[j])>0){
                strcpy(tmp,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],tmp);
            }
        }
    }
    for (int i=0; i<n; i++){
        strcpy(t,s[i]);
        for (int i=0; i<strlen(t); i++){
            strncpy(u+i,t+strlen(t)-i-1,1);
        }
        u[strlen(t)]='\0';
        printf("%s\n",u);
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",t);
         ^