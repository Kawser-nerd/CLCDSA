//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "D"
#define TASKMOD "large"

typedef long long ll;
typedef long double ld;

const int MAXN = 2100;
int c[MAXN][MAXN];
const int MOD = 1000000007;

void madd(int& a, int b){
	if ((a += b) >= MOD) a -= MOD;
}

int mmul(int a, int b){
	return (a * 1LL * b) % MOD;
}

void PreCalc(){
	c[0][0] = 1;
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++){
			if (i) madd(c[i][j], c[i-1][j]);
			if (i && j) madd(c[i][j], c[i-1][j-1]);
		}
}

struct node {
	node* next[26];
	int cnt, end;
	node(){
		memset(next, 0, sizeof(next));
		cnt = end = 0;
	}
};

const int MAXMEM = 1e6;
node mem[MAXMEM];
int memptr;
int m, n;

node* newnode(){
	assert(memptr < MAXMEM);
	mem[memptr] = node();
	return &mem[memptr++];
}

int calc(node* v/*, string cur = ""*/) {
	vector<int> res(v->cnt + 1);
	res[0] = 1;
	for (int i = 0; i < 26; i++){
		if (!v->next[i]) continue;
		int tmp = calc(v->next[i]/*, cur + char('A' + i)*/);
		vector<int> nres(v->cnt + 1);
		for (int j = 0; j <= (int)res.size(); j++)
			for (int k = max(0, v->next[i]->cnt-j); j + k <= v->cnt && k <= v->next[i]->cnt; k++) {
				int coef = mmul(c[j][v->next[i]->cnt - k], c[v->cnt - j][k]);
				coef = mmul(coef, res[j]);
				madd(nres[j + k], mmul(tmp, coef));
			}
		res = nres;
	}
	for (int i = 0; i < v->end; i++){
		vector<int> nres(v->cnt + 1);
		int tmp = 1;
		for (int j = 0; j <= (int)res.size(); j++)
			for (int k = max(0, 1-j); j + k <= v->cnt && k <= 1; k++) {
				int coef = mmul(c[j][1 - k], c[v->cnt - j][k]);
				coef = mmul(coef, res[j]);
				madd(nres[j + k], mmul(tmp, coef));
			}
		res = nres;
		
	}
//	eprintf("calc(%s[%d]) = %d\n", cur.c_str(), v->cnt, res[v->cnt]);
	return res[v->cnt];
}

void solve(){
	memptr = 0;
	node* root = newnode();
	scanf("%d %d",&m,&n);
	int ans = 0;
	for (int i = 0; i < m; i++){
		static char buf[1000];
		scanf("%s",buf);
		node* v = root;
		for (int j = 0; ; j++) {
			if (v->cnt < n){
				v->cnt++;
				ans++;
			}
			if (!buf[j]) break;
			if (!v->next[buf[j] - 'A'])
			    v->next[buf[j] - 'A'] = newnode();
			v = v->next[buf[j] - 'A'];
		}
		v->end++;
	}

	int cnt = calc(root);
	cnt = mmul(cnt, c[n][root->cnt]);
	printf("%d %d\n", ans, cnt);
}


int main(){
  freopen(TASKNAME"-"TASKMOD".in","r",stdin);
  freopen(TASKNAME"-"TASKMOD".out","w",stdout);
	
  PreCalc();
  TIMESTAMP(PreCalc);	

  char buf[1000];
  int testNum;
  gets(buf);
  sscanf(buf,"%d",&testNum);

  for (int testId = 1; testId <= testNum; testId++){
  	if (testId <= 20 || testId >= testNum - 20 || testId % 10 == 0)
	  	TIMESTAMPf("Test %d",testId);
  	printf("Case #%d: ",testId);
  	solve();                        
  }
      
  TIMESTAMP(end);
  return 0;
}