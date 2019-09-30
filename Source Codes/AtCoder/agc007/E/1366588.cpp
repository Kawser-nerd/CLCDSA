//#pragma GCC optimize(2)
#include<cstdio>
#define L 1<<23
#define C (c=*A++)
#define ENS //__attribute__((optimize("-O2")))
#define NES //__attribute__((optimize("-O2"))) __inline__ __attribute__((always_inline))
#define N 131073

struct node{long long s,t;NES bool operator<(const node&b){return (s==b.s&&t<b.t)||s<b.s;}}v[N<<5],t1[N],t2[N];
int n,l[N],r[N],a[N],lf[N],rf[N],cnt,wt,ss[19];char fl[L],*A=fl;long long mid;
NES void read(int&x){char c;for(x=0;'0'>C||c>'9';);while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+c-48,C;}NES void print(long long x){if(!x)putchar(48);else{for(wt=0;x;ss[++wt]=x%10,x/=10);for(;wt;putchar(ss[wt--]+48));}}
NES bool dfs(int x)
{
	if(!l[x])return v[lf[x]=rf[x]=++cnt]=(node){a[x],a[x]},true;int le=l[x],ri=r[x];
	if(!dfs(le)||!dfs(ri))return false;int s1=0,s2=0,i,j;
	for(lf[x]=cnt+1,j=rf[ri],i=rf[le];i>=lf[le];i--)
	{
		for(;j>=lf[ri]&&v[i].t+v[j].s>mid;j--);
		if(j+1==lf[ri])break;t1[++s1]=(node){v[i].s,v[j].t};
	}
	for(j=rf[le],i=rf[ri];i>=lf[ri];i--)
	{
		for(;j>=lf[le]&&v[i].t+v[j].s>mid;j--);
		if(j+1==lf[le])break;t2[++s2]=(node){v[i].s,v[j].t};
	}int p1=s1,p2=s2;
	if(p1||p2)
		if(!p2||(p1&&t1[p1]<t2[p2]))v[++cnt]=(node){t1[p1].s+a[x],t1[p1].t+a[x]},p1--;
		else v[++cnt]=(node){t2[p2].s+a[x],t2[p2].t+a[x]},p2--;
	while(p1||p2)
		if(!p2||(p1&&t1[p1]<t2[p2])){if(v[cnt].t>t1[p1].t+a[x])v[++cnt]=(node){t1[p1].s+a[x],t1[p1].t+a[x]};p1--;}
		else{if(v[cnt].t>t2[p2].t+a[x])v[++cnt]=(node){t2[p2].s+a[x],t2[p2].t+a[x]};p2--;}
	return(rf[x]=cnt)>=lf[x];
}
ENS int main()
{int i,fa;long long le,ri;
	for(fl[fread(fl,1,L,stdin)]=EOF,read(n),i=2;i<=n;read(a[i]),ri+=a[i],i++)if(read(fa),l[fa])r[fa]=i;else l[fa]=i;
	for(;ri&&(cnt=0,mid=ri>>1,dfs(1));ri>>=1);for(le=mid;le<ri;mid=(le+ri)>>1,cnt=0,dfs(1)?ri=mid:le=mid+1);print(ri);
} ./Main.cpp:11:51: warning: for loop has empty body [-Wempty-body]
NES void read(int&x){char c;for(x=0;'0'>C||c>'9';);while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+c-48,C;}NES void print(long long x){if(!x)putchar(48);else{for(wt=0;x;ss[++wt]=x%10,x/=10);for(;wt;putchar(ss[wt--]+48));}}
                                                  ^
./Main.cpp:11:51: note: put the semicolon on a separate line to silence this warning
./Main.cpp:11:179: warning: for loop has empty body [-Wempty-body]
NES void read(int&x){char c;for(x=0;'0'>C||c>'9';);while('0'<=c&&c<='9')x=(x<<3)+(x<<1)+c-48,C;}NES void print(long long x){if(!x)putchar(48);else{for(wt=0;x;ss[++wt]=x%10,x/=10);for(;wt;putchar(ss[wt--]+48));}}
                                                                                                                                                                                  ^
./Main.cpp:11:179: note: put the semicolon on a separate line to silence this warning
./Main.cpp:28:3: warning: add explicit braces to avoid dangling ...