#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
    return *(int*)b-*(int*)a;
}
int main(void){
    int n,i,*a,sum=0;
    scanf("%d",&n);
    a=(int*) malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),cmp);
    for(i=0;i<n;i+=2){
        sum+=a[i];
    }
    printf("%d\n",sum);
    free(a);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^