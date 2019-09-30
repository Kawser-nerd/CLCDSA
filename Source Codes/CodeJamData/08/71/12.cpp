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
#define Maxn 10000

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

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int , int> ii;
typedef complex<int> pnt;

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

FILE *in = fopen("1.in" , "r");
FILE *op = fopen("1.out" , "w");

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

int ans;
bool Matrix[Maxn + 1][Maxn + 1];
int sons[Maxn + 1][Maxn + 1];
int ind[Maxn + 1];
int Dy[Maxn + 1];
map<string , int> mix;
int n;

int main(void){
	int C;
	fscanf(in , "%d" , &C);
	FOR(i , 1 , C){
		init();
		ans = INT_MIN;
		process();
		fprintf(op , "Case #%d: %d\n" , i , ans);
		out();
	}
	fclose(in);
	fclose(op);
	return 0;
}

int fi(char name_c[100]){
	string name = name_c;
	int rtn;
	if(mix.find(name) == mix.end()){
		rtn = mix.size() + 1;
		mix[name] = rtn;
	}
	rtn = mix[name];
	return rtn;
}

void init(void){
	mix.clear();
	fscanf(in , "%d" , &n);
	FOR(i , 1 , n){
		ind[i] = 0;
		sons[i][0] = 0;
		Dy[i] = 0;
		FOR(j , 1 , n){
			Matrix[i][j] = false;
		}
	}
	char now[100];
	char from[100];
	int t;
	int f;
	FOR(i , 1 , n){
		int m;
		fscanf(in , "%s %d" , now , &m);
		t = fi(now);
//		fprintf(stderr , "%s %d\n" , now , t);
		FOR(j , 1 , m){
			fscanf(in , "%s" , from);
			if(from[0] <= 'Z'){
				f = fi(from);
				ind[t]++;
				Matrix[f][t] = true;
				sons[t][++sons[t][0]] = f;
//				fprintf(stderr , "%d %d\n" , f , t);
			}
		}
	}
}

bool pri(int a , int b){
	return (Dy[a] >= Dy[b]);
}

int cal(int P){
	int sn = sons[P][0];
	int rtn = 0;
	sort(&sons[P][1] , &sons[P][sn + 1] , pri);
	FOR(i , 1 , sn){
		//(i-1) occupied
		//Dy[sons[P][i]] needed
		rtn = max(rtn , (i - 1) + Dy[sons[P][i]]);
	}
	return rtn;
}

void process(void){
	queue<int> Q;
	FOR(i , 1 , n){
		if(ind[i] == 0){
			Q.push(i);
			ind[i] = -1;
		}
	}
	while(!Q.empty()){
		int now = Q.front();
//		fprintf(stderr , "%d\n" , now);
		Q.pop();
		
		int tmp = cal(now);
		tmp = max(tmp , sons[now][0] + 1);

		Dy[now] = tmp;
		ans = max(ans , Dy[now]);

		FOR(j , 1 , n){
			if(Matrix[now][j]){
				ind[j]--;
				if(ind[j] == 0){
					Q.push(j);
					ind[j] = -1;
				}
			}
		}
	}
}

void out(void){
}
