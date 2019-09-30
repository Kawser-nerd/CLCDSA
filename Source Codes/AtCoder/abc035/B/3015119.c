#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char s[100001];
    int t,x=0,y=0,q=0,i;
    scanf("%s%d",s,&t);
    for(i=0;i<strlen(s);i++){
        if(s[i]=='L')x--;
        else if(s[i]=='R')x++;
        else if(s[i]=='U')y++;
        else if(s[i]=='D')y--;
        else q++;
    }
    if(t==1)printf("%d\n",abs(x)+abs(y)+q);
    else{
        for(i=0;i<q;i++){
            if(x!=0){
                if(x>0)x--;
                else x++;
            }
            else{
                if(y>0)y--;
                else y++;
            }
        }
        printf("%d\n",abs(x)+abs(y));
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",s,&t);
     ^