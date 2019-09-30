#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const R PI = acos(-1);
const int MAXN = 1<<10;
const int P = 1e9+7;

struct R3{
	R x, y, z;

	R3(){}
	R3(R x, R y, R z): x(x), y(y), z(z){}

	R3 operator+ (const R3& o) const{
		return R3(x+o.x, y+o.y, z+o.z);
	}

	R3 operator- (const R3& o) const{
		return R3(x-o.x, y-o.y, z-o.z);
	}

	R dot (const R3& o) const{
		return x*o.x + y*o.y + z*o.z;
	}

	R norm2() const{
		return dot(*this);
	}

	R norm() const{
		return sqrt(norm2());
	}

	void read(){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

R3 a[MAXN];
R3 v[MAXN];
bool vis[MAXN];
int q[MAXN];
int n;
R S;

bool check(R S){
	int h, t;
	int i, j, k;
	memset(vis, 0, sizeof vis);
	vis[0] = 1;
	t = h = 0;
	q[t++] = 0;
	while(h < t){
		i = q[h++];
		for(j = 0; j < n; j++)
			if(!vis[j] && (a[i]-a[j]).norm() <= S){
				vis[j] = true;
				q[t++] = j;
			}
	}
	return vis[1];
}

int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){
		int i, j, k;
		R l, r;
		scanf("%d%lf", &n, &S);
		//printf("%f\n", S);
		for(i = 0; i < n; i++){
			a[i].read();
			v[i].read();
		}
		l = 0;
		r = 1000*3;
		while(r-l > 1e-6){
			R mid = (l+r)/2;
			if(check(mid))
				r = mid;
			else
				l = mid;
		}
		R ans = (l+r)/2;

		printf("Case #%d: %.10f\n", i0, ans);
	}
	return 0;
}
