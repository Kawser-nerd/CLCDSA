#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(x,y)( ((x)>(y))?(x):(y) )
int wall[2001234];
struct Atk{
    int d,n,w,e,s,dd,dp,ds;
}a[5000];
int q[2234567][4];
int qNum;
int x2[3000000];
int x[2001234];
int xNum;
int cmp(const void *a,const void*b){
    int *p = (int*)a;
    int *q = (int*)b;
    return p[0]-q[0];
}
int cmp2(const void *a,const void*b){
    return *(int*)a-*(int*)b;
}

int bsX(int X){
    int l=0,r=xNum,m;
    while(l<=r){
        m = (l+r)/2;
        if(x[m]>X)r=m-1;
        else if(x[m]<X)l=m+1;
        else return m;
    }
    return -1;
}
int main(){
    int t,T;
    int n;
    int i,j,k;
    int ans;
    scanf("%d",&T);
    for(t=1;t<=T;++t){
        scanf("%d",&n);
        for(i=0;i<n;++i){
            scanf("%d %d %d %d %d %d %d %d"
                  ,&a[i].d,&a[i].n,&a[i].w,&a[i].e,&a[i].s
                  ,&a[i].dd,&a[i].dp,&a[i].ds);
            //a[i].w += 500;
            //a[i].e += 500;
        }
        for(i=qNum=xNum=0;i<n;++i){
            for(j=0;j<a[i].n;++j){
                q[qNum][0] = a[i].d;
                q[qNum][1] = a[i].w;
                q[qNum][2] = a[i].e;
                q[qNum][3] = a[i].s;
                x2[xNum++] = a[i].w;
                x2[xNum++] = a[i].e;
                ++qNum;
                a[i].d += a[i].dd;
                a[i].w += a[i].dp;
                a[i].e += a[i].dp;
                a[i].s += a[i].ds;
            }
        }
        qsort(x2,xNum,sizeof(x2[0]),cmp2);
        x[0] = x2[0];
        for(i=j=1;i<xNum;++i){
            if(x2[i]!=x2[i-1])x[j++] = x2[i];
        }
        xNum = j;
        ans = 0;
        memset(wall,0,sizeof(wall));
        qsort(q,qNum,sizeof(q[0]),cmp);
        for(i=0;i<qNum;){
            for(k=i;k<qNum;++k){
                for(j=bsX(q[k][1]);j<xNum&&x[j]<q[k][2]&&wall[j]>=q[k][3];++j);
               // printf("%d %d~%d %d ",q[k][0],q[k][1],q[k][2],q[k][3]);
                if(x[j]<q[k][2]){
                    ++ans;
                   // puts(" OK");
                }//else puts(" GG");
                if(k+1!=qNum && q[k][0]==q[k+1][0])continue;
                break;
            }
            for(;i<=k;++i){
                for(j=bsX(q[i][1]);j<xNum&&x[j]<q[i][2];++j){
                    wall[j] = MAX(wall[j],q[i][3]);
               //     printf("%d = %d\n",x[j],wall[j]);
                }
            }
        }

        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}

