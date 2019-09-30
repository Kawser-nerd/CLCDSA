#include <stdio.h>
#include <stdlib.h>
int dessort(const void *a, const void *b){
    return *(int*)b-*(int*)a;
}
int main(void){
    int n,ans=0;
    scanf("%d",&n);
    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    qsort (a,n,sizeof(int),dessort);
    for (int i=0; i<n; i+=2){
        ans+=a[i];
    }
    printf("%d\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^