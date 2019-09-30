#include <stdio.h>
int pow(int a,int b);
int main(void){
    int n,k;
    scanf("%d%d",&n,&k);
    int ans = pow(k-1,n-1);
    ans *= k;
    printf("%d\n",ans);
    return 0;
}

int pow(int a,int b){
    int c=1,i=0;
    while(i<b)
    {
        c*=a;
        i++;
    }
    return c;
} ./Main.c:2:5: warning: conflicting types for built-in function ‘pow’
 int pow(int a,int b);
     ^
./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&k);
     ^