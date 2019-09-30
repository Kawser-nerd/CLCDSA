#include <stdlib.h>
#include <stdio.h>
int compare(const void *a, const void *b){
	long long int *A = (long long int *)a;
	long long int *B = (long long int *)b;
	if (*A > *B) return 1;
	if (*A < *B) return -1;
	return 0;
}
int main()
{   long long n,a[200001],cnt=0,ss=1;
    long long sub[200004]={0};
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sub[i+1]=0;
        sub[i+1]=sub[i]+a[i];
        //printf("sub[%d]=%lld\n",i+1,sub[i+1]);
    }
    qsort(sub,n+1,sizeof(long long),compare);
    //printf("sorted succesfully!\n");
    for(int i=0;i<n;i++){
        //printf("sub[%d]=%lld,ss=%d\n",i,sub[i],ss);
            if(sub[i]==sub[i+1]){
                ss++;
                }else{
                    cnt+=ss*(ss-1)/2;
                    ss=1;
                }
    }
    cnt+=(ss*(ss-1)/2);
    printf("%lld",cnt);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld",&a[i]);
         ^