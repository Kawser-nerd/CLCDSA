#include <stdio.h>

int main() {
    long t,tt,i,r,c,w,t1,ans;
    freopen("A-large.in.txt", "r", stdin);
    freopen("A-large.out.txt", "w", stdout);
    
    scanf("%ld",&t);
    for (tt=1;tt<=t;tt++){
        scanf("%ld%ld%ld",&r,&c,&w);
        for (t1=0,i=w;i<=c;i+=w,t1++);
        ans=t1*(r-1);
        if (t1*w==c){
            ans+=t1+w-1;
        }
        else {
            ans+=t1+w;
        }
        printf("Case #%ld: %ld\n",tt,ans);
    }
    return 0;
}
