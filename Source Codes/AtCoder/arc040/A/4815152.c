#include <stdio.h>
#include <stdlib.h>
int main(void){
    int n,i,j,r=0,b=0;
    char *s;
    scanf("%d",&n);
    s=(char*) malloc(sizeof(char)*(n+1));
    for(i=0;i<n;i++){
        scanf("%s",s);
        for(j=0;j<n;j++){
            if(s[j]=='R') r++;
            if(s[j]=='B') b++;
        }
    }
    printf("%s\n",r>b?"TAKAHASHI":(r<b?"AOKI":"DRAW"));
    free(s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s);
         ^