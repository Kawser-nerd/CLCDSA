#include<stdio.h>
#define NIL -1

int main(){
    int n;
    scanf("%d",&n);
    int x[n+1],i;
    for(i=1;i<=n;i++)scanf("%d",&x[i]);
    int ans[n*n+1],first[n*n+1];
    for(i=1;i<=n*n;i++)ans[i]=NIL,first[i]=NIL;
    for(i=1;i<=n;i++)ans[x[i]]=i,first[x[i]]=i;
    
    int j=1,flag=1;  /*flag 1?? 0??*/
    
    while(j<=n*n){
        if(ans[j]!=NIL){
            int count=1,k=1;
            while(count<=ans[j]-1 && k<=j-1){
                if(ans[k]==NIL){
                    ans[k]=ans[j];
                    count++;
                }
                k++;
            }
            if(count!=ans[j])flag=0;
        }
        j++;
    }
    
    j=n*n;
    while(j>=1){
        if(first[j]!=NIL){
            int count=1,k=n*n;
            while(count<=n-ans[j] && k>=1){
                if(ans[k]==NIL){
                    ans[k]=ans[j];
                    count++;
                }
                k--;
            }
            if(count!=n-ans[j]+1)flag=2;
        }
        j--;
    }
    int Count[n+1];
    for(i=1;i<=n;i++)Count[i]=0;
    for(i=1;i<=n*n;i++){
        if(ans[i]==NIL)flag=3;
        else Count[ans[i]]++;
        
        if(first[i]!=NIL && Count[first[i]]!=first[i])flag=4;
        
    }
    
    
    if(flag!=1)printf("No\n");
    else{
        printf("Yes\n");
        for(i=1;i<=n*n;i++){
            printf("%d ",ans[i]);
        }
    }
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:8:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=1;i<=n;i++)scanf("%d",&x[i]);
                      ^