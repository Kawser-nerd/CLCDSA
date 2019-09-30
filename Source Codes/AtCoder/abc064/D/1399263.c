#include <stdio.h>

int main(void){
    int n;
    char s[100];
    int i,cnt=0,pre=0;
    int d[100];//d[i]?s???i???????(???-)???
    int x;//x=min(d[0],d[1],...d[n];
    //d[s]=0??x=0??????
    scanf("%d %s",&n,s);
    for(i=0;i<n;i++){
        if(s[i]=='(')cnt++;
        if(s[i]==')'){
            if(cnt!=0)cnt--;
            else pre++;
        }
    }
    for(i=0;i<pre;i++){
        printf("(");
    }
    printf("%s",s);
    for(i=0;i<cnt;i++)printf(")");
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %s",&n,s);
     ^