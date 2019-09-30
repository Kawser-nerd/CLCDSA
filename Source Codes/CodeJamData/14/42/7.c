#include <stdio.h>

long a[1100];

int main(){
    long t,tt,i,j,k,n,ans;
    
    freopen("B-large.in.txt", "r",stdin);
    freopen("B-large.out.txt", "w",stdout);

    
    scanf("%ld",&t);
    for (tt=1;tt<=t;tt++){
        scanf("%ld",&n);
        for (i=0;i<n;i++){
            scanf("%ld",a+i);
        }
        for (i=0,ans=0;i<n;i++){
            for (j=1,k=0;j<n-i;j++){
                if (a[j]<a[k])
                    k=j;
            }
            if (k>(n-i-k-1))
                ans+=n-i-k-1;
            else
                ans+=k;
            for (j=k;j<n-i-1;j++)
                a[j]=a[j+1];
        }
        printf("Case #%ld: %ld\n",tt,ans);
    }
    return 0;
}

