#define inf 100000000
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define M 1000000007
char s[333],bubun[333];
char a[3]={'a','b','c'};
int n;
void solve(int i){
    if(i==n){
        printf("%s\n",s);
        return ;
    }
    s[i]='a';
    solve(i+1);
    s[i]='b';
    solve(i+1);
    s[i]='c';
    solve(i+1);
    return ;
}
int min(int a,int b){
    if(a<b)return a;
    else return b;
}

int main(void){
    scanf("%d",&n);
    solve(0);
      } ./Main.c: In function ‘main’:
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^