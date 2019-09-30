#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int abs(int a){
    if(a<0)return -a;
    return a;
}
int n,x,y;
int ok[123456] = {0,1};
int s;
double ans;
void DFS(int now,int n,int Y,int x,int y,int l,int r,double tt){
    if(now >=n){
        //printf("%d %d %d %lf\n",Y,l,r,tt);
        if(x<0 && l>y){
            ans+=tt;
        }
        if(x>0 && r>y){
            ans+=tt;
        }
        return ;
    }
    if(l==Y){
        DFS(now+1,n,Y,x,y,l,r+1,tt);
    }else if(r==Y){
        DFS(now+1,n,Y,x,y,l+1,r,tt);
    }else {
        DFS(now+1,n,Y,x,y,l+1,r,tt/2.0);
        DFS(now+1,n,Y,x,y,l,r+1,tt/2.0);
    }
}
int main(){
    int T,t;
    int i,j;

    for(i=j=2;i<20;++i){
        ok[i] = ok[i-1]+j*2+1;
        j+=2;
    }
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%d %d %d",&n,&x,&y);
        s = (abs(x)+abs(y))/2;
        printf("Case #%d: ",t);
        for(i=0;ok[i+1]<=n;++i);
        if(i>s){
            ans = 1.0;
        }else {
            if(i<s)ans = 0.0;
            else {s = n-ok[i];
                ans = 0.0;
                DFS(0,s,(ok[i+1]-ok[i])/2,x,y,0,0,1.0);
            }
        }
        printf("%lf\n",ans);


    }

    return 0;
}
