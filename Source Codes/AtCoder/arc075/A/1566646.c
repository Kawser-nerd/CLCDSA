#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int cmp( const void *p, const void *q ) {
    return *(int*)p - *(int*)q;}

int main(void){
    long long int i,N,s[100],A=0,B=1;
    scanf("%lld",&N);

    for(i=0;i<N;i++){
        scanf("%lld",&s[i]);
    }

    for(i=0;i<N;i++){
        A+=s[i];
    }
    
   
    
    if(A%10==0){
        qsort(s,N,sizeof(long long int),cmp);
        for(i=0;i<N;i++){
            if(s[i]%10!=0){
                A=A-s[i];
                B=1;
                break;
            }
            B=0;

        }
    }


   if(B==1){ printf("%lld",A);}
   if(B==0){printf("0");}
    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&N);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&s[i]);
         ^