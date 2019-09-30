#include <stdio.h>
int MAX(int a,int b){
    return a>=b?a:b;
}
int main()
{   int n,x=0;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    int max=x;
    for(int i=0;i<n;i++){
        if(s[i]=='I'){
            x++;
            max=MAX(max,x);
        }else{
            x--;
        }
    }
    printf("%d",max);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^