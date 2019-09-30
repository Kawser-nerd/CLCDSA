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

#define P 0
#define N 1

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
#define MaxB (1 << 16)
#define MaxR 15
#define MaxC 15

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int , int> ii;
typedef complex<int> pnt;

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

FILE *in = fopen("4.in" , "r");
FILE *op = fopen("4.out" , "w");

void init(void);
int process(int , int , int);
void out(void);

const int pn = 8;
const int py[pn + 1] = {0 , -1 , -1 , -1 , 1 , 1 , 1 , 0 , 0};
const int px[pn + 1] = {0 , -1 , 0 , 1 , -1 , 0 , 1 , -1 , 1};


int Dy[MaxB + 1][MaxR + 1][MaxC + 1];
int R , C;
int ST;
int Sy , Sx;
char ans[2][10] = {
	"A" , "B"
};

int main(void){
	int C;
	fscanf(in , "%d" , &C);
	FOR(i , 1 , C){
//		fprintf(stderr , "%d\n" , i);
		init();
		Dy[ST][Sy][Sx] = process( ST  , Sy , Sx );
		fprintf(op , "Case #%d: %s\n" , i , ans[Dy[ST][Sy][Sx]]);
		out();
	}
	fclose(in);
	fclose(op);
	return 0;
}

void init(void){
	memset(Dy , -1 , sizeof(Dy));
	fscanf(in , "%d %d" , &R , &C);
	int bias = 1;
	ST = 0;
	FOR(i ,1 , R){
		FOR(j , 1 , C){
			char c;
			fscanf(in , "%c" , &c);
			while(c != '.' && c != '#' && c != 'K'){
				fscanf(in , "%c" , &c);
			}
//			fprintf(stderr , "%c" , c);
			if(c == 'K'){
				Sy = i;
				Sx = j;
				ST += bias;
			} else if(c == '#'){
				ST += bias;
			}
			bias <<= 1;
		}
//		fprintf(stderr , "\n");
	}
}

void load(int now , bool board[MaxR + 1][MaxC + 1]){
	FOR(i , 1 , R){
		FOR(j , 1 , C){
			int t = now & 1;
			now >>= 1;
			board[i][j] = (t == 1);
		}
	}
}

int get_state(int now , int y , int x){
	int rtn = now + (1 << ((y - 1) * C + x - 1));
	return rtn;
}

int process(int now , int y , int x){
	bool board[MaxR + 1][MaxC + 1];
	load(now , board);
	int t , t2;
//	fprintf(stderr , "%d %d %d\n" , now ,  y , x);
	FOR(i , 1 , pn){
		t = y + py[i];
		t2 = x + px[i];
		if(t > 0 && t2 > 0 && t <= R && t2 <= C && !board[t][t2]){
			int to = get_state(now , t , t2);
			if(Dy[to][t][t2] == -1){
				Dy[to][t][t2] = process(to , t , t2);
			}
			if(Dy[to][t][t2] == N) return P;
		}
	}
	return N;
}

void out(void){
}

