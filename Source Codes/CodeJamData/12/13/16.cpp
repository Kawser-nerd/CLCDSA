#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <assert.h>
#include <math.h>
#include <string.h>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)
#define MOD(a,b) (((a)%(b)+(b))%(b))
#define REP(i,n) for (int i = 0; i < (n); i++)

struct br {
	ll z, n;
	br(ll a = 0) {z=a;n=1;}
	br(ll a, ll b) {z=a;n=b;}
};

bool operator<(const br &a, const br &b) {
	ll az = a.z, an = a.n, bz = b.z, bn = b.n;
	if (an < 0) {
		az = -az;
		an = -an;
	}
	if (bn < 0) {
		bz = -bz;
		bn = -bn;
	}
	return az*bn < bz*an;
}
br operator*(const br &a, const br &b) {
	return br(a.z*b.z,a.n*b.n);
}
br operator+(const br &a, const br &b) {
	return br(a.z*b.n+b.z*a.n,a.n*b.n);
}
br abs(const br &a) {
	return br(abs(a.z),abs(a.n));
}
long double fl(const br &a) {
	return (long double)a.z/a.n;
}

int T, N;
bool C[100];
ll P[100];
ll V[100];
br erg;


struct ev {
	int a, b, c;
	br t;
};
bool operator<(const ev &a, const ev &b) {
	return a.t < b.t;
}

int pa(int a, int b) {
	return N*a+b;
}

int comp[2500];
bool vorg[2500];
int vora[2500];
int dist[2500];

bool addkante(int a, int b, int l) {
	if (comp[a] == comp[b]) {
		return (dist[a]+l)%2 == dist[b];
	} else {
		REP(i,N*N) {
			if (comp[i] != comp[b] || i == b)
				continue;
			dist[i] = (dist[i]+dist[b]+l+dist[a])%2;
			comp[i] = comp[a];
		}
		dist[b] = (l+dist[a])%2;
		comp[b] = comp[a];
		if (vorg[a] && vorg[b] && (vora[a]+vora[b]+l)%2 != 0)
			return false;
		if (vorg[b] && !vorg[a])
			swap(a,b);
		if (vorg[a] && !vorg[b]) {
			REP(i,N*N) {
				if (comp[i] != comp[b] || i == b)
					continue;
				vorg[i] = true;
				vora[i] = (vora[a]+l+dist[b]+dist[i])%2;
			}
		}
		return true;
	}
}

int main() {
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		scanf("%d ", &N);
		REP(i,N) {
			char c;
			scanf("%c %lld %lld ", &c, &V[i], &P[i]);
			C[i] = (c == 'R');
			assert(c == 'R' || c == 'L');
		}
		vector<ev> evs;
		erg = br(1E9,1);
		REP(a,N) {
			REP(b,N) {
				if (V[a] == V[b])
					continue;
				br e1(5+P[b]-P[a],V[a]-V[b]);
				br e2(-5+P[b]-P[a],V[a]-V[b]);
				br t = min(e1,e2);
				//printf("%d %d: %Lf=%lld/%lld\n", a, b, (long double)t.z/t.n, t.z, t.n);
				if (t < 0)
					continue;
				REP(c,N) {
					if (c == a || c == b)
						continue;
					if (abs(P[a]-P[c]+(V[a]-V[c])*(t+br(1,1000000000))) < 5) {
						//printf("%d %d %d %Lf\n", a, b, c, (long double)t.z/t.n);
						/*printf("%d %d %d %Lf %Lf %lld %lld\n", a, b, c, 
							   (long double)t.z/t.n, 
							   fl(abs(P[a]-P[c]+(V[a]-V[c])*(t+br(1,10000)))), 
							   abs(P[b]-P[c]+(V[b]-V[c])*(t+br(1,10000))).z,
							     abs(P[b]-P[c]+(V[b]-V[c])*(t+br(1,10000))).n
  							);*/
						if (abs(P[b]-P[c]+(V[b]-V[c])*(t+br(1,1000000000))) < 5) {
						 	erg = min(erg,t);
							//printf("hi %Lf\n", fl(t));
						} else {
							ev e;
							e.a = a;
							e.b = b;
							e.c = c;
							e.t = t;
							evs.push_back(e);
						}
					}
				}
			}
		}
		sort(evs.begin(),evs.end());
		
		REP(i,N*N) {
			comp[i] = i;
			dist[i] = 0;
		}
		
		REP(a,N) {
			REP(b,N) {
				if (abs(P[a]-P[b]) < 5) {
					vorg[pa(a,b)] = true;
					vora[pa(a,b)] = C[a];
				} else {
					vorg[pa(a,b)] = false;
				}
				addkante(pa(a,b),pa(b,a),1);
			}
		}
		
		FOREACH(e,evs) {
			if (!addkante(pa(e->a,e->b),pa(e->a,e->c),0)) {
				erg = min(erg,e->t);
				break;
			}
		}
		
		if (erg.z == 1E9)
			printf("Possible\n");
		else
			printf("%Lf\n", (long double)erg.z/erg.n);
	}
	return 0;
}
