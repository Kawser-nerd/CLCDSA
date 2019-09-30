#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    char s[10];
    int l,c=0;
    if(scanf("%s",s)==1) l=strlen(s);
    if(s[0]=='A'&&islower(s[1])&&islower(s[l-1])){
        for(int i=2;i<l;i++){
            if(isupper(s[i])&&s[i]!='C'){printf("WA\n");return 0;}
            else if(s[i]=='C')c++;if(c>1){printf("WA\n");return 0;}
        }   
        if(c==0){printf("WA\n");return 0;}
        else{printf("AC\n");return 0;}
    }else{ printf("WA\n"); return 0;}
}