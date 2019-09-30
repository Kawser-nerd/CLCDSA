#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
#define x first
#define y second
#define lch 2*x
#define rch 2*x+1
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=3e5+5,T=2e6+5;
const ll mod=1e9+7;
struct node{
    int maxv,add;
}tree[T];
void Pushdown(int x){
    if(tree[x].add){
        tree[lch].add+=tree[x].add;
        tree[lch].maxv+=tree[x].add;
        tree[rch].add+=tree[x].add;
        tree[rch].maxv+=tree[x].add;
        tree[x].add=0;
    }
}
void Pushup(int x){
    tree[x].maxv=max(tree[lch].maxv,tree[rch].maxv);
}
void Add(int x,int l,int r,int pl,int pr,int add){
    if(pl<=l&&r<=pr){
        tree[x].maxv+=add;
        tree[x].add+=add;
        return ;
    }
    int mid=(l+r)>>1;
    if(pl<=mid)
        Add(x*2,l,mid,pl,pr,add);
    if(pr>mid)
        Add(x*2+1,mid+1,r,pl,pr,add);
    Pushdown(x);
    Pushup(x);
}
int w,h,n;
pii p[N],sta[N],stb[N];
int topa,topb;
int ans;
void work(){
    sort(p+1,p+n+1);
    memset(tree,0,sizeof tree);
    topa=topb=0;
    for(int i=1;i<n;i++){
        if(p[i].y<=h/2){
            int nxt=i-1;
            while(topa&&p[i].y>sta[topa].y){
                Add(1,1,n,sta[topa].x,nxt,sta[topa].y-p[i].y);
                nxt=sta[topa--].x-1;
            }
            if(nxt!=i-1)
                sta[++topa]=pii(nxt+1,p[i].y);
        }
        else{
            int nxt=i-1;
            while(topb&&p[i].y<stb[topb].y){
                Add(1,1,n,stb[topb].x,nxt,p[i].y-stb[topb].y);
                nxt=stb[topb--].x-1;
            }
            if(nxt!=i-1)
                stb[++topb]=pii(nxt+1,p[i].y);
        }
        sta[++topa]=pii(i,0);
        stb[++topb]=pii(i,h);
        Add(1,1,n,i,i,h-p[i].x);
        Pushdown(1);
        Pushup(1);
        ans=max(ans,tree[1].maxv+p[i+1].x);
    }
}
int main()
{
    scanf("%d%d%d",&w,&h,&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    p[++n]=pii(0,0);
    p[++n]=pii(w,h);
    work();
    for(int i=1;i<=n;i++)
        swap(p[i].x,p[i].y);
    swap(w,h);
    work();
    printf("%d\n",ans*2);
}