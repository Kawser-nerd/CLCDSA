#include<stdio.h>
 
int main(void)
{
   int a,b,c,d[100],e,i,z=1;

    scanf("%d%d%d",&a,&b,&c);
    
    for(i=0;i<a && i<b;i++){
        if(a%z == 0 && b%z == 0){
            d[e] = z;
            e++;
        }
        z++;
    }
    printf("%d\n",d[e-c]);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&c);
     ^