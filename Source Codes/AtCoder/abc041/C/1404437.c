#include <stdlib.h>
#include <stdio.h>
typedef struct{
    int id,num;
}student;
int cmp(const void *a,const void *b){
    if (((student *)a)->num>((student*)b)->num)return 1;
    else if(((student *)a)->num<((student*)b)->num)return -1;
    else return 0;
}
int main(void){
    student a[100000];
    int i;
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        a[i].id=i+1;
        scanf("%d",&a[i].num);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=n-1;i>=0;i--){
        printf("%d\n",a[i].id);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i].num);
         ^