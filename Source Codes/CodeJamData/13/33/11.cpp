#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define DAY 676061
using namespace std;
struct data{
    int l,r,v;
    data(int _l=0,int _r=0,int _v=0){l=_l;r=_r;v=_v;}
};
vector<data>day[DAY];
int num[2000000],nn;
void fix(int &x){
    int tmp=lower_bound(num,num+nn,x)-num;
    x=tmp*2;
}
int mi[16000000],to[16000000];
void init(int L,int R,int id){
    mi[id]=0;
    to[id]=0;
    if(L==R)return;
    int mm=(L+R)>>1;
    init(L,mm,id*2);
    init(mm+1,R,id*2+1);
}
bool qq(int L,int R,int id,int ll,int rr,int v){
    if(R<ll||L>rr)return 1;
    if(L>=ll&&R<=rr)return mi[id]>=v;
    int mm=(L+R)>>1;
    if(to[id]){
        to[id]=0;
        if(mi[id*2]<mi[id]){
            mi[id*2]=mi[id];
            to[id*2]=1;
        }
        if(mi[id*2+1]<mi[id]){
            mi[id*2+1]=mi[id];
            to[id*2+1]=1;
        }
    }
    bool flag=1;
    if(!qq(L,mm,id*2,ll,rr,v))flag=0;
    if(!qq(mm+1,R,id*2+1,ll,rr,v))flag=0;
    mi[id]=min(mi[id*2],mi[id*2+1]);
    return flag;
}
void add(int L,int R,int id,int ll,int rr,int v){
    if(R<ll||L>rr)return;
    if(L>=ll&&R<=rr){
        if(v>mi[id]){
            mi[id]=v;
            to[id]=1;
        }
        return;
    }
    int mm=(L+R)>>1;
    if(to[id]){
        to[id]=0;
        if(mi[id*2]<mi[id]){
            mi[id*2]=mi[id];
            to[id*2]=1;
        }
        if(mi[id*2+1]<mi[id]){
            mi[id*2+1]=mi[id];
            to[id*2+1]=1;
        }
    }
    add(L,mm,id*2,ll,rr,v);
    add(mm+1,R,id*2+1,ll,rr,v);
    mi[id]=min(mi[id*2],mi[id*2+1]);
}
int main(){
    
    int N,T,cs=0,i,j,k;
    scanf("%d",&T);
    while(T--){
        int res=0;
        for(i=0;i<DAY;i++)day[i].clear();
        scanf("%d",&N);
        nn=0;
        for(i=0;i<N;i++){
            int dd,n,w,e,s,delta_dd,delta_p,delta_s;
            scanf("%d%d%d%d%d%d%d%d",&dd,&n,&w,&e,&s,&delta_dd,&delta_p,&delta_s);
            for(k=1;k<=n;k++){
                day[dd].push_back(data(w,e,s));
                num[nn++]=w;
                num[nn++]=e;
                dd+=delta_dd;
                w+=delta_p;
                e+=delta_p;
                s+=delta_s;
            }
        }
        sort(num,num+nn);
        nn=unique(num,num+nn)-num;
        for(i=0;i<DAY;i++){
            for(j=0;j<day[i].size();j++){
                fix(day[i][j].l);
                fix(day[i][j].r);
            }
        }
        init(0,nn*2,1);
        for(i=0;i<DAY;i++){
            for(j=0;j<day[i].size();j++){
                if(!qq(0,nn*2,1,day[i][j].l,day[i][j].r,day[i][j].v))res++;
            }
            for(j=0;j<day[i].size();j++){
                add(0,nn*2,1,day[i][j].l,day[i][j].r,day[i][j].v);
            }
        }
        printf("Case #%d: %d\n",++cs,res);
    }
    return 0;
}
