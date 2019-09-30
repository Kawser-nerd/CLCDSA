#include <stdio.h>



int main(void){
    int Q;
    scanf("%d",&Q);
    for(int unko=0;unko<Q;unko++){
        long long int A,B;
        scanf("%lld %lld",&A,&B);
        if(A>B){long long int po=A;A=B;B=po;}
        long long int ans=A-1;
        long long int left=0;
        long long int right=B+1;
        while(1){
            long long int mid=(left+right)/2;
            if(A<mid){long long int buri=(A+1+mid)/2;if(buri*(A+1+mid-buri)<A*B)left=mid;else right=mid;}
            else if(mid*(A+1)<A*B)left=mid;else right=mid;
            if(right-left<=1)break;
           // else printf("%lld %lld\n",right,left);
        }
        ans+=left;
        printf("%lld\n",ans);
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&Q);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld %lld",&A,&B);
         ^