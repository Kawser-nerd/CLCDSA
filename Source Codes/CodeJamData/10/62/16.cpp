#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define Rep(i,n) for(int i=0;i<n;++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define MP make_pair
#define pb push_back

typedef vector<int> VI;
typedef pair<int,int> PII;

int n;
int a[33][33];
int st, res;
bool vs[33];

void go(int i, int step) {
	//cerr << "go " << i << " " << step << endl;
	vs[i] = true;
	// quay lai
	if(a[i][st]) {
		res = max( res, step);
	}
	For(j,1,n)if(a[i][j]) {
		// cerr << i << " " << j << endl;
		if(!vs[j]) {
			go(j, step + 1);
		}
	}
	vs[i] = false;
}

int main() {
	int ntest;
	scanf("%d", &ntest);

	For(test,1,ntest) {
		// int n;		
		scanf("%d", &n);
		memset(a,0,sizeof(a));
		a[1][2] = a[2][1] = a[1][3] = a[3][1] = a[2][3] = a[3][2] = 1;
		
		For(i,4,n) {
			int u,v;
			scanf("%d%d",&u,&v);
			a[i][u]=a[u][i]=1;
			a[i][v]=a[v][i]=1;
		}
		
		//For(i,1,n) For(j,1,n) if(a[i][j]) cerr << i << " " << j << endl;
		
		res = 0;
		For(i,1,n) {
			st = i;
			memset(vs,0,sizeof(vs));
			go(st, 1);
		}
		
		printf("Case #%d: ", test);
		printf("%d\n", res);
		fflush(stdout);
	}
    return 0;
}
