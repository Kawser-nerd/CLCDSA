#include <cstdio>
#include <cstdlib>
#include <string>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <cctype>
using namespace std;
#define maxl 1010
int nsc, sc;
int p, k, l;
int mas[maxl];
void init(){
	int i;
	scanf("%d%d%d", &p, &k, &l);
	for(i=1;i<=l;i++)
		scanf("%d", &mas[i]);
}
void solve(){
	int i;
	long long res=0;
	sort(mas+1, mas+l+1);
	int cnt=1;
	int nkey=1;
	for(i=l;i>=1;i--){
		res+=mas[i]*cnt;
		nkey++;
		if (nkey==k+1){
			cnt++;
			nkey=1;
		}
	}
	printf("Case #%d: %lld\n", sc, res);
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d", &nsc);
	for(sc=1; sc<=nsc; sc++){
		init();
		solve();	
	}
	return 0;
}