#include <stdio.h>
long getbignum();
int main(void){
    long a,b,c;
    scanf("%ld%ld%ld",&a,&b,&c);
    
    long tmp = a*b%getbignum();
    printf("%ld\n",tmp*c%getbignum());
    return 0;
}

long getbignum(){
    long ans =1;
    int i=0;
    while(i<9)
    {
        ans*=10;
        i++;
    }
    return ans+7;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld%ld",&a,&b,&c);
     ^