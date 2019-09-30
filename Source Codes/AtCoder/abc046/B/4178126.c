#include <stdio.h>
int Pow(int a,int b){
    int c=1,i=0;
    while(i<b)
    {
        c*=a;
        i++;
    }
    return c;
}
int Pow(int a,int b);
int main(void){
    unsigned int n=0,k=0;
    scanf("%d %d",&n,&k);
    unsigned int sum=0;
    sum=k*Pow((k-1),(n-1));
    printf("%d",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&k);
     ^