#include <stdio.h>
int main(void){
    int n,i,v=-1,x=0;
    char s[101];
    scanf("%d%s",&n,s);
    for(i=0;i<n;i++){
        if(s[i]=='I'){
            x++;
            if(v<x) v=x;
        }
        if(s[i]=='D'){
            if(v<x) v=x;
            x--;
        }
    }
    printf("%d\n",v);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%s",&n,s);
     ^