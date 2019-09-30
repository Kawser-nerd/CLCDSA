#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int number;
    int value;
    int compress;
} point;
int compare_first(const void *a,const void*b){
    point x=*(point *)a;
    point y=*(point *)b;
    int p=x.value,q=y.value;
    return p>q?1:-1;
}
int compare_second(const void *a,const void*b){
    point x=*(point *)a;
    point y=*(point *)b;
    int p=x.number,q=y.number;
    return p>q?1:-1;
}
int main()
{   int n;
    scanf("%d",&n);
    point a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].value);
        a[i].number=i;
    }
    qsort(a,n,sizeof(point),compare_first);
    a[0].compress=0;
    int k=0;
    for(int i=1;i<n;i++){
        if(a[i].value>a[i-1].value){
            k++;
        }
        a[i].compress=k;
    }
    qsort(a,n,sizeof(point),compare_second);
    for(int i=0;i<n;i++){
        printf("%d\n",a[i].compress);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:25:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i].value);
         ^