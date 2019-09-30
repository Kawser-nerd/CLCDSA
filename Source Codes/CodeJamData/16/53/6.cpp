#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

struct P {
	typedef const P& R;
	typedef double T;
	T x, y, z;
	explicit P(T x=0, T y=0, T z=0) : x(x), y(y), z(z) {}
	bool operator<(R p) const {
		return x<p.x || x==p.x && (y<p.y || y==p.y && z<p.z);
	}
	bool operator==(R p) const { return x==p.x&&y==p.y&&z==p.z; }
	P operator+(R p) const { return P(x+p.x, y+p.y, z+p.z); }
	P operator-(R p) const { return P(x-p.x, y-p.y, z-p.z); }
	P operator*(T d) const { return P(x*d, y*d, z*d); }
	P operator/(T d) const { return P(x/d, y/d, z/d); }
	T dot(R p) const { return x*p.x + y*p.y + z*p.z; }
	P cross(R p) const {
		return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
	}
	T dist2() const { return x*x + y*y + z*z; } //distance^2
	double dist() const { return sqrt((double)dist2()); }
	//Azimuthal angle (longitude) to x-axis in interval [-pi, pi]
	double phi() const { return atan2(y, x); } 
	//Zenith angle (latitude) to the z-axis in interval [0, pi]
	double theta() const { return atan2(sqrt(x*x+y*y),z); }
	P unit() const { return *this/(T)dist(); } //makes dist()=1
	//returns unit vector normal to *this and p
	P normal(P p) const { return cross(p).unit(); }
	operator double() const { return dist(); }
};

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
	int find(int x) {
		if (e[x] < 0) return x;
		return e[x] = find(e[x]);
	}
};

void solve() {
	int N, S;
	cin >> N >> S;
	vector<P> pos(N), delta(N);
	rep(i,0,N) {
		cin >> pos[i].x >> pos[i].y >> pos[i].z;
		cin >> delta[i].x >> delta[i].y >> delta[i].z;
	}
	auto works = [&](double d) {
		UF uf(N);
		rep(i,0,N) rep(j,i+1,N) {
			double di = (pos[i] - pos[j]).dist2();
			if (di > d*d) continue;
			uf.join(i, j);
		}
		return uf.same_set(0, 1);
	};
	double lo = 0, hi = 2000;
	rep(i,0,60) {
		double mid = (lo + hi) / 2;
		if (works(mid)) hi = mid;
		else lo = mid;
	}
	cout << setprecision(10) << fixed << hi << endl;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	rep(i,0,N) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
