using namespace std;
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cstring>
#include<cmath>
#include<fstream>

typedef long double D; typedef long long LL; typedef pair<int,int> pii;
#define ALL(v) (v).begin(),(v).end()
#define REP(i, n) for (int i (0); i < (n); i ++)
#define FORIT(a,b, it) for(__typeof(b)it(a);it!=(b);++it)
#define FOREACH(v, it) FORIT((v).begin(),(v).end(),it)
#define len(v) ((int)(v).size())
#define append push_back
#define _ make_pair
#define fi first
#define se second
#define add insert
#define remove erase
#define TWO(x) (1<<(x))
#define UNIQUE(v) (v).erase(unique(ALL(v)),(v).end())
const int infInt (1010101010);
const LL  infLL  (4 * LL (infInt) * LL (infInt));

template<class T>void pv(T a,T b){FORIT(a,b,it)cout<<*it<<" ";cout<<endl;}

inline void chmin(int&x,int y){x=min(x,y);}
inline void chmax(int&x,int y){x=max(x,y);}

/*
 * iteration 0: (X,Y) = (0,0)
 * iteration 1: (X,Y) = (-2,0), (-1,1), (0,2), (1,1), (2,0)
 * iteration 2: (X,Y) = (-4,0), (-3,1), (-2,2), (-1,3), (0,4), (1,3), (2,2), (3,1), (4,0)
 * iteration K: place 4*K+1 blocks: all (X,Y) with abs(X)+Y = 2*K.
 */

int count_squares(int iterations) {
	/*int total = 0;
	for (int k = 0; k < iterations; k ++) {
		total += 4*k + 1;
	}
	return total;*/
	return 4*(iterations*(iterations-1)/2) + iterations;
}

#define W 2005
double p[W][W];
void output_answer(int case_id, double value) {
	printf("Case #%d: %.9lf\n", case_id, value);
}
void solve(int case_id, int n, int x, int y) {
	int n_iterations = 0;
	while (count_squares(n_iterations) < n) n_iterations = n_iterations + 1;
	int last_iteration = n_iterations - 1;
	int iteration_placed = (abs(x) + y) / 2;
	if (iteration_placed < last_iteration) output_answer(case_id, 1.0); else
	if (iteration_placed > last_iteration) output_answer(case_id, 0.0); else {
		if (count_squares(n_iterations) == n) {
			output_answer(case_id, 1.0);
		}
		else {
			if (x == 0) {
				output_answer(case_id, 0.0);
			}
			else {
				int placed = n - count_squares(n_iterations - 1);
				for (int i=0;i<W;i++)for(int j=0;j<W;j++)p[i][j]=0;
				p[0][0] = 1;
				for (int a=0;a<=2*last_iteration;a++)
				for (int b=0;b<=2*last_iteration;b++) {
					((a+1 <= 2*last_iteration) ? p[a+1][b] : p[a][b+1]) +=  p[a][b]/2.0;
					((b+1 <= 2*last_iteration) ? p[a][b+1] : p[a+1][b]) +=  p[a][b]/2.0;
				}
				int position = y;
				double answer = 0;
				for (int a=0;a<=2*last_iteration;a++)
				for (int b=0;b<=2*last_iteration;b++)
				if (a + b == placed)
				if (a > position)
				answer += p[a][b];
				output_answer(case_id, answer);
			}
		}
	}
}

int main() {
	int T;
	scanf("%d",&T);
	for (int case_id=1; case_id<=T; case_id++) {
		int n, x, y;
		cin >> n >> x >> y;
		solve(case_id, n, x, y);
	}
}
