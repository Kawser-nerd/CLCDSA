#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <utility>
#define LL long long

using namespace std;

int tt;
int n;
int a[10000];
LL ans;
LL fac[13];

void swap(int st,int ed,int len) {
	for (int i=0;i<len;++i)
		swap(a[st+i],a[ed+i]);
}

void dfs(int i,int cnt) {
	if (i==n) {
		ans+=fac[cnt];
		return;
	}
		int now=0;
		int cur=-1,cur1=-1;
		for (int j=0;j<1<<n;j+=1<<(i+1))
			if (a[j]+(1<<i)!=a[j+(1<<i)]) {
				now++;
				if (cur==-1) cur=j;
				else cur1=j;
			}
		if (now==0) dfs(i+1,cnt);
		if (now==2) {
			int p1=a[cur],p2=a[cur+(1<<i)];
			int q1=a[cur1],q2=a[cur1+(1<<i)];
			if (q1+(1<<i)==p2 && p1+(1<<i)==q2) {
				swap(cur1,cur,(1<<i));
				dfs(i+1,cnt+1);
				swap(cur1,cur,(1<<i));
				swap(cur1+(1<<i),cur+(1<<i),(1<<i));
				dfs(i+1,cnt+1);
				swap(cur1+(1<<i),cur+(1<<i),(1<<i));
			}
			if (q1+(1<<i)==p1 && q2+(1<<i)==p2) {
				swap(cur,cur1+(1<<i),1<<i);
				dfs(i+1,cnt+1);
				swap(cur,cur1+(1<<i),1<<i);
			}
			if (p1+(1<<i)==q1 && p2+(1<<i)==q2) {
				swap(cur+(1<<i),cur1,1<<i);
				dfs(i+1,cnt+1);
				swap(cur+(1<<i),cur1,1<<i);
			}
		}
		if (now==1) {
			if (a[cur]==a[cur+(1<<i)]+(1<<i)) {
				swap(cur,cur+(1<<i),1<<i);
				dfs(i+1,cnt+1);
				swap(cur,cur+(1<<i),1<<i);
			}
		}


}

int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);

	scanf("%d",&tt);
	fac[0]=1;
	for (int i=1;i<=12;++i)
		fac[i]=fac[i-1]*i;
	for (int ii=1;ii<=tt;++ii) {
		scanf("%d",&n);
		for (int i=0;i<1<<n;++i)
			scanf("%d",&a[i]);

		ans=0;
		dfs(0,0);

		printf("Case #%d: ",ii);
		cout << ans << endl;
	}

}
