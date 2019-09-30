#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[301],t[300][301]={0};
    int k,a,i,j,l;
    scanf("%s%d",s,&k);
    if(k>strlen(s)){
        puts("0");
        return 0;
    }
    a=strlen(s)-k+1;
    for(i=0;i<strlen(s)-k+1;i++){
        l=0;
        for(j=i;j<k+i;j++){
            t[i][l]=s[j];
            l++;
        }
    }
    for(i=0;i<strlen(s)-k;i++){
        for(j=i+1;j<strlen(s)-k+1;j++){
            if(strcmp(t[i],t[j])==0){
                a--;
                break;
            }
        }
    }
    printf("%d\n",a);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",s,&k);
     ^