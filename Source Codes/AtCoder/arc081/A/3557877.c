#include <stdlib.h>
#include <stdio.h>
int compare(const void *a,const void *b){
    return *(long long*)b - *(long long*)a ;
}
int main()
{
    long long n,h=0,i,w=0,flag=0,a[100001];
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    qsort(a,n,sizeof(long long),compare);
    for(i=0;i<n-1;i++){
        //printf("a[%lld]=%lld\n",i,a[i]);
        if(a[i]==a[i+1]&&flag==0){
            h=a[i];
            i++;
            flag=1;
        }else if(a[i]==a[i+1]){
            w=a[i];
            break;
        }
        
    }
    printf("%lld",h*w);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^