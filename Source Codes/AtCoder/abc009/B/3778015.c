#include<stdio.h>
#include<stdlib.h>
int compare(const void *a , const void *b){
    return *(int*)b-*(int*)a;
}
int main(){
    int n,a[100],i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(int),compare);
    for(i=0;i<n;i++){
        if(a[i+1]<a[i]){
            printf("%d\n",a[i+1]);
            return 0;
        }
    }
    } ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^