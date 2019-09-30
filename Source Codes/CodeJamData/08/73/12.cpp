#include<cstdio>
#include<climits>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<sstream>
#include<cassert>
#include<complex>

#define FOR(a , b , c) for(int a = (int)b; a<=(int)c; a++)
#define FORD(a , b , c) for(int a = (int)b; a>=(int)c; a--)
#define pb push_back
#define mk make_pair
#define sz(v) ((int)(v).size())
#define all(v) v.begin() , v.end()
#define set(x, with) memset(x , with , sizeof(x))
#define same(a,b) (fabs((a)-(b))<0.000000001)
#define even(a) ((a) % 2 == 0)
#define odd(a) ((a) % 2 == 1)
#define Maxn 30
#define MaxC 4
#define MaxQ 50000

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int , int> ii;
typedef complex<int> pnt;

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

FILE *in = fopen("3.in" , "r");
FILE *op = fopen("3.out" , "w");

void init(void);
void process(void);
void out(void);

const int pn = 4;
const pnt pv[pn] = {
	pnt (0 , -1),
	pnt (0 , 1),
	pnt (-1 , 0),
	pnt (1 , 0)
};

int n;
int qn;
double p[Maxn + 1][MaxC + 1];
double Queue[2][MaxQ + 1];
int Qs[2];
double ans;

int main(void){
	int C;
	fscanf(in , "%d" , &C);
	FOR(i , 1 , C){
		init();
		process();
		fprintf(op , "Case #%d: %.8lf\n" , i , ans);
		out();
	}
	fclose(in);
	fclose(op);
	return 0;
}

void init(void){
	fscanf(in , "%d %d" , &qn , &n);
	FOR(i , 1 , n){
		FOR(j , 1 , 4){
			fscanf(in , "%lf" , &p[i][j]);
		}
	}
}

bool pri(double a , double b){
	return a > b;
}

void process(void){
	Qs[0] = 4;
	FOR(i , 1 , 4){
		Queue[0][i] = p[1][i];
	}
	sort(&Queue[0][1] , &Queue[0][Qs[0] + 1] , pri);
	if(Qs[0] > qn){
		Qs[0] = qn;
	}
	int from = 0 , to = 1;
	FOR(i , 2 , n){
		Qs[to] = 0;
		FOR(j , 1 , Qs[from]){
			FOR(k , 1 , 4){
				Queue[to][++Qs[to]] = Queue[from][j] * p[i][k];
			}
		}
		sort(&Queue[to][1] , &Queue[to][Qs[to] + 1] , pri);
		if(Qs[to] > qn){
			Qs[to] = qn;
		}
		from = to;
		to = !from;
	}
	ans = 0;
	double p = 1;
	FOR(i , 1 , Qs[from]){
		ans += p * Queue[from][i];
	}
}

void out(void){
}
