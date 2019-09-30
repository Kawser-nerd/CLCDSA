#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int main(void){
    int n,m;
    scanf("%d%d",&n,&m);
    int a[m],b[m];
    long long c[m],dis[n];
    for (int i=0; i<m; i++){
        scanf("%d%d%lld",&a[i],&b[i],&c[i]);
        a[i]--;
        b[i]--;
        c[i]=c[i]*(-1);
    }
    for (int i=0; i<n; i++){
        dis[i]=LLONG_MAX;
    }
    dis[0]=0;
    for (int i=0; i<n-1; i++){
        for (int j=0; j<m; j++){
            if (dis[a[j]]==LLONG_MAX){
                continue;
            }
            if (dis[b[j]]>dis[a[j]]+c[j]){
                dis[b[j]]=dis[a[j]]+c[j];
            }
        }
    }
    
    long long ans=dis[n-1];
    bool neg[n];
    for (int i=0; i<n; i++){
        neg[i]=false;
    }
    
    
    for (int j=0; j<n; j++){
        for (int i=0; i<m; i++){
            if (dis[a[i]]==LLONG_MAX){
                continue;
            }
            if (dis[b[i]]>dis[a[i]]+c[i]){
                dis[b[i]]=dis[a[i]]+c[i];
                neg[b[i]]=true;
            }
            if (neg[a[i]]==true){
                neg[b[i]]=true;
            }
        }
    }
    if (neg[n-1]==true){
        printf("inf\n");
    } else {
        printf("%lld\n",ans*-1);
    }
    return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&n,&m);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%lld",&a[i],&b[i],&c[i]);
         ^