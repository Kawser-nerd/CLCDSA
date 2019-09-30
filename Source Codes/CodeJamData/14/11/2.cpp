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

#define TASKNAME "A"
#define TASKMOD "large"

typedef long long ll;
typedef long double ld;

void PreCalc(){
}


string operator^(string a, string b) {
	string res;
	for (int i = 0; i < (int)a.size(); i++)
		res += '0' + ((a[i] - '0') ^ (b[i] - '0'));
	return res;
}

int count(string s){
	int res = 0;
	for (int i = 0; i < (int)s.size(); i++)
		res += s[i] == '1';
	return res;
}


void solve(){
	int n;
	scanf("%d %*d",&n);
	vector<string> a(n),b(n);
	for (int i = 0;  i < n; i++){
		static char buf[200];
		scanf("%s", buf);
		a[i] = buf;
	}
	for (int i = 0;  i < n; i++){
		static char buf[200];
		scanf("%s", buf);
		b[i] = buf;
	}

	sort(a.begin(), a.end());

	int res = a[0].size() + 1;

	for (int i = 0; i < n; i++){
		string tmp = a[0] ^ b[i];
//		eprintf("tmp = |%s|\n", tmp.c_str());
		vector<string> c(n);
		for (int j = 0; j < n; j++) {
			c[j] = b[j] ^ tmp;
//			eprintf("%s\n", c[j].c_str());
	    }
//	    eprintf("\n");
		sort(c.begin(), c.end());
		if (c == a)
			res = min(res, count(tmp));
	}

	if (res == (int)a[0].size() + 1)
		puts("NOT POSSIBLE");
	else
		printf("%d\n", res);
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