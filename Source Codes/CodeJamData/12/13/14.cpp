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
int si[55],xi[55];
int ci[55];
int n;
const double eps=1e-12;
const double INF=1e100;
inline double ABS(double x){return x<0?-x:x;}
int m;
vector<int> ed[12000];
vector<int> red[12000];
double remt1[55][55];
double remt2[55][55];
struct XD{
    int pid;
    double t1,t2;
    XD(double tt1=0,double tt2=0):t1(tt1),t2(tt2){
        ed[m].clear();
        pid=m;
        m++;
    }
    bool conf(const XD& b)const{
        return max(t1,b.t1)<min(t2,b.t2);
    }
};
vector<pair<int,int> > allp;
vector<XD> pts[55];
struct ev{
    double t;
    int c;
    bool operator<(const ev& b)const{
        if(ABS(t-b.t)<eps)return c<b.c;
        return t<b.t;
    }
};
ev evs[200];
inline void adde(int a,int b){ed[a].push_back(b);}
double maxt;
int vis[12000],visid=0;
inline bool isa(int x){
    if(x>=m)x-=m;
    return pts[allp[x].first][allp[x].second].t1<maxt;
}
inline bool rt(int x,int y,bool de=0){
    if(x>=m)x-=m;
    if(y>=m)y-=m;
    if(x==y)return 1;
    int xx=allp[x].first;
    int yy=allp[y].first;
    double t1=remt1[xx][yy];
    double t2=remt2[xx][yy];
    if(t2<0)return 0;
    if(t1>=maxt)return 0;
    if(de)printf("xx=%d yy=%d t1=%lf t2=%lf\n",xx,yy,t1,t2);
    t2=min(t2,maxt);
    double tt1=pts[xx][allp[x].second].t1;
    double tt2=pts[xx][allp[x].second].t2;
    double ty1=pts[yy][allp[y].second].t1;
    double ty2=pts[yy][allp[y].second].t2;
    tt1=min(max(tt1,ty1),maxt);
    tt2=min(min(tt2,ty2),maxt);
    assert(tt1<tt2+eps);
    return max(tt1,t1)<min(tt2,t2)-eps;
}
int ids[12000],idc;
int sccid[12000];
inline void dfs(int np){
    vis[np]=visid;
    int i;
    for(i=0;i<ed[np].size();i++){
        int y=ed[np][i];
        if(vis[y]!=visid&&isa(y)&&rt(np,y))dfs(y);
    }
    ids[idc++]=np;
}
inline void dfs2(int np,int ii){
    vis[np]=visid;
    sccid[np]=ii;
    int i;
    for(i=0;i<red[np].size();i++){
        int y=red[np][i];
        if(vis[y]!=visid&&isa(y)&&rt(np,y))dfs2(y,ii);
    }
}
inline bool solve(bool de=0){
    int i,j,k;
    visid++;
    idc=0;
    for(i=0;i<2*m;i++)if(isa(i)&&vis[i]!=visid){
        dfs(i);
    }
    int sc=0;
    visid++;
    for(i=idc-1;i>=0;i--){
        int y=ids[i];
        if(isa(y)&&vis[y]!=visid){
            dfs2(y,sc);
            sc++;
        }
    }
    for(i=0;i<m;i++){
        if(isa(i)&&sccid[i]==sccid[i+m]){
            if(de)printf("conf: i=%d\n",i);
            return 0;
        }
    }
    return 1;
}
bool tmt[100];
int main(){
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        int i,j,k,q,w;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            char tmp[3];
            scanf("%s%d%d",tmp,&si[i],&xi[i]);
            ci[i]=(tmp[0]=='L');
        }
        m=0;
        for(i=0;i<n;i++)for(j=0;j<n;j++){remt1[i][j]=0;remt2[i][j]=-1;}
        for(i=0;i<n;i++){
            pts[i].clear();
            int ec=0,f=0;
            for(j=0;j<n;j++){
                if(i==j)continue;
                if(si[i]>si[j]){
                    if(xi[i]>=xi[j]+5)continue;
                    double t1=(xi[j]-xi[i]-5.0)/(si[i]-si[j]);
                    double t2=(xi[j]-xi[i]+5.0)/(si[i]-si[j]);
                    if(t1<0){
                        t1=0;
                        f=1;
                    }
                    remt1[i][j]=t1;
                    remt2[i][j]=t2;
                    evs[ec].t=t1;evs[ec].c=1;ec++;
                    evs[ec].t=t2;evs[ec].c=-1;ec++;
                }else if(si[i]<si[j]){
                    if(xi[i]<=xi[j]-5)continue;
                    double t1=(xi[i]-xi[j]-5.0)/(si[j]-si[i]);
                    double t2=(xi[i]-xi[j]+5.0)/(si[j]-si[i]);
                    if(t1<0){
                        t1=0;
                        f=1;
                    }
                    remt1[i][j]=t1;
                    remt2[i][j]=t2;
                    evs[ec].t=t1;evs[ec].c=1;ec++;
                    evs[ec].t=t2;evs[ec].c=-1;ec++;
                }else{
                    if(xi[i]-xi[j]>=5||xi[i]-xi[j]<=-5)continue;
                    f=1;
                    remt1[i][j]=0;
                    remt2[i][j]=INF;
                    evs[ec].t=0;evs[ec].c=1;ec++;
                    evs[ec].t=INF;evs[ec].c=-1;ec++;
                }
            }
            tmt[i]=f;
            if(ec==0)continue;
            sort(evs,evs+ec);
            double lt=0;
            int cnt=0;
            for(j=0;j<ec;j++){
                if(evs[j].c==1){
                    cnt++;
                    if(cnt==1)lt=evs[j].t;
                }else{
                    cnt--;
                    if(cnt==0)pts[i].push_back(XD(lt,evs[j].t));
                }
            }
        }
        allp.clear();
        allp.resize(m);
        for(i=0;i<n;i++)for(j=0;j<pts[i].size();j++){
            allp[pts[i][j].pid]=make_pair(i,j);
        }
        for(i=0;i<2*m;i++)ed[i].clear();
        for(i=0;i<n;i++){
            if(pts[i].size()==0)continue;
            if(tmt[i]){
                int a=pts[i][0].pid;
                if(ci[i]==0)adde(a+m,a);
                else adde(a,a+m);
            }
            for(j=i+1;j<n;j++){
                for(q=0;q<pts[i].size();q++){
                    for(k=0;k<pts[j].size();k++){
                        if(pts[i][q].conf(pts[j][k])){
                            int a=pts[i][q].pid;
                            int b=pts[j][k].pid;
                            adde(a,b+m);
                            adde(b,a+m);
                            adde(a+m,b);
                            adde(b+m,a);
                        }
                    }
                }
            }
        }
        /*for(i=0;i<n;i++)for(j=0;j<pts[i].size();j++){
            printf("%d: i=%d (%lf %lf)\n",pts[i][j].pid,i,pts[i][j].t1,pts[i][j].t2);
        }*/
        for(i=0;i<2*m;i++)red[i].clear();
        for(i=0;i<2*m;i++)for(j=0;j<ed[i].size();j++){
           // printf("%d -> %d\n",i,ed[i][j]);
            red[ed[i][j]].push_back(i);
        }
        printf("Case #%d: ",cas++);
        maxt=INF;
        if(solve()){
            puts("Possible");
        }else{
            double l=0,r=200000;
            for(i=0;i<100;i++){
                maxt=(l+r)/2;
                if(solve())l=(l+r)/2;
                else r=(l+r)/2;
            }
            //maxt=0.000;
            //rt(1,6,1);
            //for(i=0;i<2*m;i++)for(j=0;j<ed[i].size();j++)if(rt(i,ed[i][j]))printf("%d->%d\n",i,ed[i][j]);
            //solve(1);
            printf("%lf\n",l);
        }
    }
}

