#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare_int(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}

int main(void){
    int n;
    scanf("%d",&n);
    int data[n];
    for(int i = 0;i<n;i++){
        scanf("%d",&data[i]);
    }
    qsort(data,n,sizeof(int),compare_int);
    double ans = 0;
    int pm = 1;
    if(n % 2 != 1){
        pm = -1;
    }
    for(int i = 0;i<n;i++){
        if(i % 2 != 0){
            ans += (double)data[i] * (double)data[i] * pm;
        }else{
            ans += (double)data[i] * (double)data[i] * pm;
        }
        pm *= -1;
    }
    printf("%-.7lf\n",ans * M_PI);
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&data[i]);
         ^