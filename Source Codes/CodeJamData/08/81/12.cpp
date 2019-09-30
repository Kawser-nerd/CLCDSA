#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:64000000")

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cctype>
#include <cassert>
#include <complex>

using namespace std;

typedef double D;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<D> vd;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back

template<typename T> T abs(T x) { return (x>0) ? x : -x; }
template<typename T> T sqr(T x) { return x*x;            }

typedef complex<D> C;

C a[3],b[3];

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	int tn;
	cin>>tn;
	for (int tst=0; tst<tn; tst++) {
		printf("Case #%d: ",tst+1);
		for (int i=0; i<3; i++) {
			D x,y;
			cin>>x>>y;
			a[i]=C(x,y);
			
		}
		for (int i=0; i<3; i++) {
			D x,y;
			cin>>x>>y;
			b[i]=C(x,y);
		}
		bool eq=true;
		for (int i=0; i<3; i++)
			if (abs(a[i].real()-b[i].real())>1e-8 || abs(a[i].imag()-b[i].imag())>1e-8)
				eq=false;
		if (eq) {
			printf("%.10lf %.10lf\n",a[0].real(),a[0].imag());
			continue;
		}
		C k=(a[1]-a[0])/(b[1]-b[0]);
		C y=a[0]-b[0]*k;
		C c=y/(C(1,0)-k);
		printf("%.10lf %.10lf\n",c.real(),c.imag());
	}

	return 0;
}
