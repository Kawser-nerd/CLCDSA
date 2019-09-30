#include <stdio.h>
#include <stdbool.h>

int main(void){
    bool sosu[100000];
    int ans[100000],q,l,r;
    ans[0]=0;
    for (int i=1; i<100000; i++){
        ans[i]=0;
        sosu[i]=true;
        for (int j=2; j<i; j++){
            if (i%j==0){
                sosu[i]=false;
                break;
            }
        }
        if (i%2!=0 && sosu[i]==true && sosu[(i+1)/2]==true){
            ans[i]=ans[i-1]+1;
        } else {
            ans[i]=ans[i-1];
        }
    }
    ans[0]=1;
    scanf("%d",&q);
    for (int i=0; i<q; i++){
        scanf("%d%d",&l,&r);
        printf("%d\n",ans[r]-ans[l-1]);
    }
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&q);
     ^
./Main.c:26:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&l,&r);
         ^