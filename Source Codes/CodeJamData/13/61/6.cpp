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
#define TASKMOD "small"

typedef long long ll;
typedef long double ld;

void PreCalc(){
}

const int MAXN = 110000;

int n,m,x;
int st[MAXN],s[MAXN],e[MAXN];

int getpos(int id,int t){
//    eprintf("%d %d %d\n", s[id], e[id], st[id]);
    int l = (e[id] - s[id]);
    if (l < 0) l += n;
    if (t > st[id] + l || t < st[id]) return -1;
    return (s[id] + t - st[id] + 100LL*n) % n;
}

void solve(){
    scanf("%d",&m);
    scanf("%d %d",&x,&n);
    for (int i = 0; i < m; i++)
        scanf("%d %d %d",&s[i], &e[i],&st[i]), s[i]--, e[i]--;


    int best = 0;
    for (int i = 0; i <= x; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; i + k <= x; k++){
                bool fail = false;
                for (int q = 0; q < m; q++)
                    if (getpos(q, i + k) == (j - k + n*100L) % n)
                        fail = true;
                if (fail) break;                        
                best = max(best, k);
//                eprintf("%d %d %d\n",i,j,k);
                for (int q = 0; q < m; q++)
                    if (getpos(q, i + k) == (j - k - 1 + n*100L) % n && getpos(q, i+k) != e[q]){
                        fail = true;
                    }
                if (fail) break;
            }
        }
    }
    printf("%d\n", best);
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
    if (testId <= 20 || testId >= testNum - 20 || testId % 10 == 0){
        TIMESTAMPf("Test %d",testId);
    }
    printf("Case #%d: ",testId);
    solve();                        
  }
      
  TIMESTAMP(end);
  return 0;
}