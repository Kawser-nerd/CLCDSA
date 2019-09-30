#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdarg.h>
#include<time.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int s,m;
int in[10100][2];
int pre[40000000];
int cnt[40000000];
int vis[40000000];
int blo[40000000],bc;
int mi;
int dx[6]={0,1,1,0,-1,-1},dy[6]={-1,0,1,1,0,-1};
inline int id(int x,int y){
    return x*mi+y;
}
inline bool ins(int x,int y){
    return x>=1&&y>=1&&x<=mi&&y<=mi&&y-x<=s&&x-y<=s;
}
inline bool one(int x,int y,int k){
    if(k==0)return x==1;
    else if(k==1)return y==1;
    else if(k==2)return x-y==s;
    else if(k==3)return x==mi;
    else if(k==4)return y==mi;
    else return y-x==s;
}
inline bool onc(int x,int y,int k){
    return one(x,y,k)&&one(x,y,(k==5?0:k+1));
}
inline int find(int x){
    return pre[x]==-1?x:pre[x]=find(pre[x]);
}
inline void init(){
    int x=(mi+2)*(mi+2);
    memset(pre,-1,sizeof(int)*x);
    memset(cnt,0,sizeof(int)*x);
    memset(vis,0,sizeof(int)*x);
}
inline int go(int x,int y,int k){
    int xx=x+dx[k],yy=y+dy[k];
    if(ins(xx,yy))return id(xx,yy);
    return -1;
}
const int INF=1000000000;
inline int ds(int x){
    int c=0;
    while(x){
        if(x&1)c++;
        x>>=1;
    }
    return c;
}
inline int minf(){
    init();
    int i,j;
    for(i=0;i<m;i++){
        int x=in[i][0],y=in[i][1];
        int np=id(x,y);
        vis[np]=1;
        int ec=-1;
        for(j=0;j<6;j++)if(one(x,y,j)){
            if(ec==-1)ec=j;
            else ec=-2;
        }
        if(ec>=0)cnt[np]|=(1<<ec);
        for(j=0;j<6;j++){
            int to=go(x,y,j);
            if(to==-1)continue;
            if(!vis[to])continue;
            to=find(to);
            if(to==np)continue;
            cnt[np]|=cnt[to];
            pre[to]=np;
        }
        if(ds(cnt[np])>=3)return i;
    }
    return INF;
}
inline int minb(){
    init();
    int i,j;
    for(i=0;i<m;i++){
        int x=in[i][0],y=in[i][1];
        int np=id(x,y);
        vis[np]=1;
        for(j=0;j<6;j++)if(onc(x,y,j)){
            cnt[np]|=(1<<j);
            break;
        }
        for(j=0;j<6;j++){
            int to=go(x,y,j);
            if(to==-1)continue;
            if(!vis[to])continue;
            to=find(to);
            if(to==np)continue;
            cnt[np]|=cnt[to];
            pre[to]=np;
        }
        if(ds(cnt[np])>=2)return i;
    }
    return INF;
}
int que[40000000],qs,qe;
inline int minr(){
    init();
    bc++;
    int i,j,k;
    for(i=0;i<m;i++){
        blo[id(in[i][0],in[i][1])]=bc;
    }
    int bln=1;
    for(i=1;i<=mi;i++)for(j=1;j<=mi;j++){
        if(!ins(i,j))continue;
        int np=id(i,j);
        if(blo[np]!=bc){
            bln++;
        }
        if(blo[np]==bc||vis[np])continue;
        qs=qe=0;
        que[qe++]=np;
        vis[np]=1;
        bool te=0;
        while(qs<qe){
            int ss=que[qs++];
            int y=(ss-1)%mi+1;
            int x=(ss-y)/mi;
            if(!te){
                for(k=0;k<6;k++)if(one(x,y,k))te=1;
            }
            for(k=0;k<6;k++){
                int t=go(x,y,k);
                if(t==-1)continue;
                if(blo[t]==bc||vis[t])continue;
                vis[t]=1;
                que[qe++]=t;
            }
        }
        int r=que[0];
        for(k=1;k<qe;k++){
            pre[que[k]]=r;
            bln--;
        }
        if(te){
            pre[r]=0;
            bln--;
        }
    }
    int mi=INF;
    for(i=m-1;i>=0;i--){
        if(bln>1)mi=min(mi,i);
        int x=in[i][0],y=in[i][1];
        int np=id(x,y);
        blo[np]=0;
        bln++;
        for(j=0;j<6;j++){
            int t=go(x,y,j);
            if(t==-1)continue;
            if(blo[t]==bc)continue;
            int f=find(t);
            if(f==np)continue;
            pre[f]=np;
            bln--;
        }
        for(j=0;j<6;j++){
            if(one(x,y,j)){
                int f=find(0);
                if(f==np)continue;
                pre[f]=np;
                bln--;
            }
        }
    }
    return mi;
}
char str[8][30]={
    "",
"fork in move ",
"bridge in move ",
"bridge-fork in move ",
"ring in move ",
"fork-ring in move ",
"bridge-ring in move ",
"bridge-fork-ring in move ",
};
inline void solve(){
    s--;
    mi=s*2+1;
    int f=minf(),b=minb(),r=minr();
    int k=min(min(f,b),r);
        /*if(s<=4){
            printf("%d %d\n",s+1,m);
            for(int i=0;i<m;i++)printf("%d %d\n",in[i][0],in[i][1]);
       }*/
    if(k==INF)puts("none");
    else{
        int x=0;
        if(f==k)x|=1;
        if(b==k)x|=2;
        if(r==k)x|=4;
        printf("%s%d\n",str[x],k+1);
    }
}
int main(){
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        int i;
        scanf("%d%d",&s,&m);
        for(i=0;i<m;i++){
            scanf("%d%d",&in[i][0],&in[i][1]);
        }
        fprintf(stderr,"%d\t",cas);
        printf("Case #%d: ",cas++);
        solve();
    }
}

