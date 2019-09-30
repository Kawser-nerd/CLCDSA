#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{   int t;
    char s[100001];
    scanf("%s",s);
    int x=0,y=0,cnt=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='U')y++;
        if(s[i]=='D')y--;
        if(s[i]=='R')x++;
        if(s[i]=='L')x--;
        if(s[i]=='?')cnt++;
    }scanf("%d",&t);
    if(t==1){
    printf("%d\n",abs(x)+abs(y)+cnt);
    }else if(abs(x)+abs(y)>=cnt){
        printf("%d\n",abs(x)+abs(y)-cnt);
    }else{
        printf("%d\n",abs(abs(x)+abs(y)-cnt)%2);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^
./Main.c:15:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     }scanf("%d",&t);
      ^