#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define swap(x,y){int tmp=x;x=y;y=tmp;}
int absI(int a){
    if(a<0)return -a;
    return a;
}
int cmp(const void*a,const void*b){
    int *p = (int*)a;
    int *q = (int*)b;
    if(p[0]!=q[0])return p[0]-q[0];
    return p[1]-q[1];
}
int T,t;
int n,m;
int p[12345][3];
int pNum;
int o,e,pi;
int main(){
    int i,j;
    int ini,ans;
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%d %d",&n,&m);
        pNum = 0;
        ini = 0;
        while(m--){
            scanf("%d %d %d",&o,&e,&pi);
            while(pi--){
                ini = (ini+(n+n-absI(e-o)+1)*(absI(e-o))/2)%1000002013;
                p[pNum][0] = o;
                p[pNum][1] = e;
                p[pNum][2] = o;
                ++pNum;
            }
        }
        qsort(p,pNum,sizeof(p[0]),cmp);
        for(i=0;i<pNum;++i){
            for(j=i+1;j<pNum;++j){
                if(p[j][1] > p[i][1] && p[j][0]>p[i][0] && p[j][0]<=p[i][1])swap(p[j][1],p[i][1]);
            }
        }
        for(i=ans=0;i<pNum;++i){
            ans = (ans+(n+n-absI(p[i][1]-p[i][0])+1)*(absI(p[i][1]-p[i][0]))/2)%1000002013;
        }
        printf("Case #%d: %d\n",t,ini-ans);
    }

    return 0;
}
