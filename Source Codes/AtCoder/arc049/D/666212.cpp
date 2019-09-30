#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N,V,bit[1<<18];

void in(int x)
{
	while (x <= V){
		bit[x] ^= 1;
		x += x & (-x);
	}
}

int out(int x)
{
	int r = 0;
	while (x){
		r ^= bit[x];
		x -= x & (-x);
	}
	return r;
}

int real(int x)
{
	return out(x);
}

int main()
{
	int N,Q;
	scanf ("%d %d",&N,&Q);
	V = (1 << (N+1)) - 1;
	while (Q--){
		int t,a,b; scanf ("%d %d %d",&t,&a,&b);
		if (t == 1){
			int res = 0, x = 1; a--;
			for (int i=0;i<N;i++){
				int s = 1 << (N - i - 1);
				int r = real(x);
				if (a >= s){
					r ^= 1;
					a -= s;
				}
				if (r) res += s;
				x = x * 2 + r;
			}
			printf ("%d\n",res+1);
		}
		if (t == 2){
			int s = 1;
			for (int i=0;i<N;i++){
				int e = s + (1 << i) - 1;
				int p = max(s,a), q = min(e,b);
				s += (1 << i);
				if (p > q) continue;

				int x = p, y = q;
				int m = 1, z = (1 << i);
				vector<pair<int, int> > lf, rg;
				while (x < y){
					if (x & 1){
						lf.push_back(make_pair((x-z)*m,(x-z)*m+m-1));
						x++;
					}
					if (~y & 1){
						rg.push_back(make_pair((y-z)*m,(y-z)*m+m-1));
						y--;
					}
					x /= 2; y /= 2;
					m *= 2; z /= 2;
				}
				if (x == y){
					lf.push_back(make_pair((x-z)*m,(x-z)*m+m-1));
				}
				while (!rg.empty()){
					lf.push_back(rg.back());
					rg.pop_back();
				}

				for (auto pr : lf){
					int u = pr.first, v = pr.second;
					int x = 1, ru = 0, rv = (1 << i), s = (1 << i);
					for (int j=0;j<=i;j++){
						if (v - u + 1 == s){
							in(ru+(1<<i));
							in(rv+(1<<i));
							break;
						}
						int r = real(x);
						s /= 2;
						if (u >= s){
							r ^= 1;
							u -= s; v -= s;
						}
						if (r) ru += s;
						else rv -= s;
						x = x * 2 + r;
					}
				}
			}
		}
	}
	return 0;
}