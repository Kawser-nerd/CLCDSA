#include <iostream>
#include <memory>
#include <algorithm>
#include <numeric>
 
#define M 1000000000000000009

using namespace std;

static int64_t getInvMod(int64_t a, int64_t m)
{
    int64_t b, x, u, q, tmp;

    b = m; x = 1; u = 0;
    while (b > 0) {
	q = a / b;
	tmp = u; u = x - q * u; x = tmp;
	tmp = b; b = a - q * b; a = tmp;
    }

    return ( x < 0 ) ? m + x : x;
}

static int64_t getComb(int n, int r)
{
    if (n < r) {
	return 0;
    }
    
    __int128 ret;
    ret = 1;
    for (int i = n; i > n - r; i--) {
	ret = (ret * i) % M;
    }

    for (int i = r; i > 0; i--) {
	__int128 invi = getInvMod(i, M);
	ret = (ret * invi) % M;
	
    }

    return (int64_t) ret;
}


int main(void){
    int n, a, b;
    
    cin >> n >> a >> b;

    int64_t v[n];
    for (int i = 0; i < n; i++) {
	cin >> v[i];
    }

    sort(v, v+n, greater<int64_t>());

    double ave = (double) accumulate(v, v+a, int64_t(0)) / a;

    cout.precision(20);
    cout << fixed << ave << endl;

    if (v[0] == v[a - 1]) {
	int count = a;
	for (int i = a; i < n; i++) {
	    if (v[i] == v[0]) {
		count++;
	    } else {
		break;
	    }
	}

	int64_t comb = 0;
	for (int i = a; i <= b; i++) {
	    comb += getComb(count, i);
	}
	cout << comb << endl;
    } else {
	int cn = 0;
	int cr = 0;

	for (int i = 0; i < n; i++) {
	    if (v[i] == v[a - 1]) {
		cn++;
		if (i <= a - 1) {
		    cr++;
		}
	    }
	}

	cout << getComb(cn, cr) << endl;
    }
    
    return 0;
}