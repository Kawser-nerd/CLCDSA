#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define DEBUG(format, args...) do { fprintf(stderr, format, ## args); fflush(stderr); } while (0)
#define PRINT(format, args...) do { fprintf(stdout, format, ## args); DEBUG(format, ## args); } while (0)

#define SIZE(__c) (int)(__c).size()
#define FOREACH(__i, __c) for (typeof(__c.begin()) __i=__c.begin(); __i!=__c.end(); ++__i)

typedef signed long long int i64;

const int OFFSET=350;
const int DY[]={-1, 0, 1, 0};
const int DX[]={0, 1, 0, -1};

int DIGIT_MODULUS;

struct QueueItem {
  int y, x, n;
  int py, px;
  QueueItem(int y, int x, int n): y(y), x(x), n(n) {}
  QueueItem(int y, int x, int n, int py, int px): y(y), x(x), n(n), py(py), px(px) {}
  bool isDigit() const { return (y+x)%2==DIGIT_MODULUS; }
};

char fd[32][32];
string dp[32][32][2*OFFSET+1];

bool inBounds(int y, int x, int N);

int main() {
  int i, j, k, n, ny, nx, N, Q, t, T;
  scanf("%d", &T);
  for (t=1; t<=T; t++) {
    scanf("%d %d", &N, &Q);
    for (i=0; i<N; i++)
      scanf("%s", fd[i]);
    DIGIT_MODULUS=!isdigit(fd[0][0]);
    queue<QueueItem> qe;
    for (i=0; i<N; i++)
      for (j=0; j<N; j++)
        if ((i+j)%2==DIGIT_MODULUS) {
          for (k=(-OFFSET); k<=OFFSET; k++)
            dp[i][j][OFFSET+k]="";
          dp[i][j][OFFSET+(fd[i][j]-'0')]+=fd[i][j];
          qe.push(QueueItem(i, j, fd[i][j]-'0'));
        }
    while (!qe.empty()) {
      QueueItem &qi=qe.front();
      for (i=0; i<4; i++) {
        ny=qi.y+DY[i];
        nx=qi.x+DX[i];
        if (inBounds(ny, nx, N))
          if (qi.isDigit())
            qe.push(QueueItem(ny, nx, qi.n, qi.y, qi.x));
          else {
            n=qi.n+(fd[qi.y][qi.x]=='+' ? +1 : -1)*(fd[ny][nx]-'0');
            if (-OFFSET<=n && n<=OFFSET) {
              string &s1=dp[ny][nx][OFFSET+n], s2;
              if (dp[ny][nx][OFFSET+n]=="") {
                s1=dp[qi.py][qi.px][OFFSET+qi.n]+fd[qi.y][qi.x]+fd[ny][nx];
                qe.push(QueueItem(ny, nx, n));
              }
              else if (SIZE(s1)==
                       SIZE(s2=dp[qi.py][qi.px][OFFSET+qi.n]+fd[qi.y][qi.x]+fd[ny][nx]) && s1>s2)
                s1=s2;
            }
          }
      }
      qe.pop();
    }
    PRINT("Case #%d:\n", t);
    while (Q--) {
      scanf("%d", &n);
      string A;
      for (i=0; i<N; i++)
        for (j=0; j<N; j++)
          if ((i+j)%2==DIGIT_MODULUS) {
            string &ss=dp[i][j][OFFSET+n];
            if (ss!="")
              if (A=="" || SIZE(A)>SIZE(ss) || SIZE(A)==SIZE(ss) && A>ss)
                A=ss;
          }
      PRINT("%s\n", A.c_str());
    }
  }
  return 0;
}

bool inBounds(int y, int x, int N) {
  return y>=0 && x<N && y<N && x>=0;
}
