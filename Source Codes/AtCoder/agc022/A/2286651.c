#include <stdio.h>
#include <string.h>




int main(void){
    char po[364];
    scanf("%s",po);
    int a=strlen(po);
    if(a!=26){
    int unko[26]={};
    for(int i=0;i<a;i++)unko[po[i]-'a']=1;
    printf("%s",po);
    for(int i=0;i<26;i++)if(unko[i]==0){printf("%c",'a'+i);return 0;}
    }
    else{
        char nari[]="zyxwvutsrqponmlkjihgfedcba";
        if(strcmp(po,nari)==0){printf("-1");return 0;}
        else{
            int now=po[a-1]-'a';
            for(int i=a-2;i>=0;i--){
                if(po[i]-'a'<now){
                    for(int j=0;j<i;j++)printf("%c",po[j]);
                    for(int j=a-1;;j--)if(po[i]<po[j]){printf("%c",po[j]);return 0;}
                }
                else now=po[i]-'a';
            }
            
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",po);
     ^