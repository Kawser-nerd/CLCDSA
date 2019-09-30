#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int main(void){
    long long n;
    scanf("%lld",&n);
    long long n1=n;
    int count=0,a[20],ans;
    bool nine=false;
    while (n1!=0){
        a[count]=n1%10;
        n1/=10;
        count++;
    }
    ans=a[count-1];
    for (int i=1; i<count; i++){
        if (nine==true){
            ans+=9;
        } else if (a[count-1-i]==9){
            ans+=9;
        } else {
            ans+=8;
            nine=true;
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^