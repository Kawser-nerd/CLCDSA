#include <stdio.h>
#include "stdlib.h"

long a[11000],b[11000];

int comp(const void *a,const void *b){
    long t;
    t=((long *)a)[0]-((long *)b)[0];
    if (t>0)
        return 1;
    else if (t<0)
        return -1;
    else
        return 0;
}

int main(){
    long t,tt,i,j,k,n,m,ans;
    
    freopen("A-large.in.txt", "r",stdin);
    freopen("A-large.out.txt", "w",stdout);

    
    scanf("%ld",&tt);
    for (t=1;t<=tt;t++){
        scanf("%ld%ld",&n,&m);
        for (i=0;i<n;i++){
            scanf("%ld",a+i);
            b[i]=0;
        }
        qsort(a, n, sizeof(long), comp);
        ans=n;
        for (j=0,i=n-1;j<i;){
            while (j<i&&((a[i]+a[j])>m))
                i--;
            if (j<i&&(a[i]+a[j]<=m)){
                b[j]=1;
                j++;
                i--;
                ans--;
            }
        }
        printf("Case #%ld: %ld\n",t,ans);
    }
    return 0;
}

