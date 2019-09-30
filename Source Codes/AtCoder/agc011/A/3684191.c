#include <stdio.h>
#include <stdlib.h>
int compare(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
int main()
{   int n,c,k;
    scanf("%d%d%d",&n,&c,&k);
    int t[n];
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    qsort(t,n,sizeof(int),compare);
    //printf("sorted\n");
    int ans=0,flag=0,first,cnt=0;
    for(int i=0;i<n;i++){
        if(flag==0){
            first=i;
            flag++;
            //printf("first=%d\n",first);
        }
        if((cnt+1)<=c&&t[i]-t[first]<=k){
            cnt++;
            //printf("cnt=%d\n",cnt);
        }else{
            //printf("last=%d\n",i-1);
            ans++;
            first=i;
            cnt=1;
        }
    }
    if(cnt!=0){ans++;
    //printf("added\n");
    }
    printf("%d",ans);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&c,&k);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&t[i]);
         ^