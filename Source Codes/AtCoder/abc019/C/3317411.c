#include <stdio.h>
#include <stdlib.h>
int assort(const void *a, const void *b){return *(int*)a-*(int*)b;}
int main(void){
    int n,ans=0,tmp=-1;
    scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
        while(a[i]%2==0){
            a[i]/=2;
        }
    }
    qsort (a,n,sizeof(int),assort);
    for (int i=0; i<n; i++){
        if (tmp<a[i]){
            tmp=a[i];
            ans++;
        }
    }
    printf("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^