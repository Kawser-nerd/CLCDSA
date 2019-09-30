#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <ctime>
#define LL long long int
#define N 1000005
using namespace std;

priority_queue <LL> Q;

int n,m,L,TC,ok;
LL t,a[N],b[N],TT=0,x;

int main(){
	scanf("%d",&TC);
	for (int C=1;C<=TC;C++){
		scanf("%d%lld%d%d",&L,&t,&n,&m);
		
		for (int i=0;i<m;i++)
			scanf("%lld",&a[i]);
		
		ok=0;
		TT=0;
		while (!Q.empty()) Q.pop();
		
		for (int i=0;i<n;i++){
			b[i]=a[i%m];
			TT+=(b[i]*2);
			if (TT>t){
				if (!ok)
					Q.push(TT-t);
				else Q.push(b[i]*2);
				ok=1;
			}
		}
		
		while (L-- && !Q.empty()){
			x = Q.top();
			Q.pop();
			TT-=(x/2);
		}
		
		printf("Case #%d: %lld\n",C,TT);
		
		
	}
	//scanf("\n");
	return 0;
}
