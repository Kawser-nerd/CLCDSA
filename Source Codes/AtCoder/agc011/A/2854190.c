#include <stdio.h>
#include <stdlib.h>

int sort(const void *a, const void *b){
    return *(int*)a-*(int*)b ;
}

int main(void){
    int n,c,k,ans=0,first=0,count=0;
    scanf("%d%d%d",&n,&c,&k);
    int t[n];
    for (int i=0; i<n; i++){
        scanf("%d",&t[i]);
    }
    qsort (t,n,sizeof(int),sort); 
    for (int i=0; i<n; i++){
        if(first==0){
            first=t[i];
        }
        count++;
        if (t[i]>first+k){
            ans++;
            first=t[i];
            count=1;
        } else if (count==c){
            ans++;
            first=0;
            count=0;
        }
    }
    if (count!=0){
        ans++;
    }
    printf ("%d\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&c,&k);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&t[i]);
         ^