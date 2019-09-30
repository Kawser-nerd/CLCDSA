#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define maxn 210

int T;
int n;
int s[maxn];
int sum;

bool enough(int ind, double x) {
	double my_score = s[ind] + sum * x;

	double rest = 1 - x;
	for (int i = 0; i < n; i++) {
		if (i == ind) continue;

		double this_score = s[i];
		if (this_score >= my_score) continue;
		double dx = (my_score - this_score) / sum;
		rest -= dx;
	}

	if (rest < 0) return true;
	return false;
}

int main() {
  scanf("%d", &T);
  for (int q = 1; q <= T; q++) {
  	scanf("%d", &n);
  	sum = 0;
  	for (int i = 0; i < n; i++) {
  		scanf("%d", &s[i]);
  		sum += s[i];
    }

    printf("Case #%d:", q);
    for (int ind = 0; ind < n; ind++) {
    	double L = 0, R = 1;
    	for (int it = 0; it < 40; it++) {
    		double av = (L + R) / 2;

    		if (enough(ind, av)) {
    			R = av;
    		} else {
    			L = av;
    		}
    	}
    	printf(" %.8lf", L * 100);
    }
    puts("");
  }

  return 0;
}
