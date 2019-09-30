#include<stdio.h>
int main(void){
    int n,i,sum;
    scanf("%d",&n);
    for(i=2;i<n;i++){
        if(n%i==0){
            if((n%10)%2&&(n%10)!=5){
                while(n!=0){
                    sum+=n%10;
                    n=(n-(n%10))/10;
                }
                if(sum%3==0){
                    printf("Not Prime\n");
                    return 0;
                }
                else{
                    printf("Prime\n");
                    return 0;
                }
            }
            else{
                printf("Not Prime\n");
                return 0;
            }
        }
    }
    if(n!=1){
        printf("Prime\n");
    }
    else{
        printf("Not Prime\n");
    }
	return 0;		
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^