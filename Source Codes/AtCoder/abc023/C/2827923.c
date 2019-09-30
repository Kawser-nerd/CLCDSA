#include <stdio.h>

int main(void){
    int t,y,k,n;
    scanf("%d%d%d%d",&t,&y,&k,&n);
    int r[n],c[n],countr[100020]={0},countc[100020]={0},amountr[100020]={0},amountc[100020]={0};
    long long ans=0;
    for (int i=0; i<n; i++){
        scanf("%d%d",&r[i],&c[i]);
        countr[r[i]-1]++;
        countc[c[i]-1]++;
    }
    for (int i=0; i<t; i++){
        amountr[countr[i]]++;
    }
    for (int i=0; i<y; i++){
        amountc[countc[i]]++;
    }
    for (int i=0; i<=k; i++){
        ans+=amountr[i]*amountc[k-i];
    }
    for (int i=0; i<n; i++){
        if (countr[r[i]-1]+countc[c[i]-1]==k){
            ans--;
        }
        if (countr[r[i]-1]+countc[c[i]-1]==k+1){
            ans++;
        }
    }
    printf("%lld\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&t,&y,&k,&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d",&r[i],&c[i]);
         ^