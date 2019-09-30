#include <stdio.h>

int main(void)
{
    char des[200001];
    scanf("%s",des);
    int i;
    
    long long int sum=0;
    long long int bnum=0;
    
    for(i=0; des[i]!='\0'; i++){
        if(des[i] == 'B'){
            bnum++;
        }
        else{
            sum += bnum;
        }
    }
    printf("%lld\n",sum);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",des);
     ^