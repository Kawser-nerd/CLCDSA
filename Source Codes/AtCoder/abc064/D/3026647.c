#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int main(void){
    int n,l=0;
    bool e=false;
    char s[250],t[250],u[2]=")";
    scanf("%d%s",&n,s);
    for (int j=0; j<strlen(s); j++){
        for (int i=0; i<strlen(s); i++){
            if (s[i]=='('){
                l++;
            } else {
                l--;
            }
            if (l<0){
                e=true;
            }
        }
        if (e==true){
            strcpy(t,s);
            s[0]='(';
            strcpy(s+1,t);
            
        }
        e=false;
        l=0;
    }
    for (int j=strlen(s)-1; j>=0; j--){
        for (int i=strlen(s)-1; i>=0; i--){
            if (s[i]==')'){
                l++;
            } else {
                l--;
            }
            if (l<0){
                e=true;
            }
        }
        if (e==true){
            strcpy(t,s);
            snprintf(s,210,"%s%s",t,u);
        }
        e=false;
        l=0;
    }    
    
    
    
    printf("%s\n",s);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%s",&n,s);
     ^