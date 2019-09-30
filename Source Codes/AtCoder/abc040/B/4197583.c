#include <stdio.h>
#define Min(a,b) a<b?a:b
int main(void){
    int n;
    scanf("%d",&n);
    
    if(n==1)
    {
        puts("0");
        return 0;
    }
    int min = n;
    int i=1;
    while(i<n)
    {
        min = Min(min,n%i+abs(i-n/i)); 
        // printf("%d %d %d\n",min,n,i);
        i++;
    }
    printf("%d\n",min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:27: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
         min = Min(min,n%i+abs(i-n/i)); 
                           ^
./Main.c:2:20: note: in definition of macro ‘Min’
 #define Min(a,b) a<b?a:b
                    ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^