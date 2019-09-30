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

char bf[108];

double FindProbability(const vector<string> &tk, int p, const set<string> &ft, double A);

int main() {
  int i, j, L, N, t, T;
  scanf("%d", &T);
  for (t=1; t<=T; t++) {
    scanf("%d\n", &L);
    vector<string> tk;
    for (i=0; i<L; i++) {
      gets(bf);
      for (j=0; bf[j]; j++)
        if (bf[j]=='(')
          tk.push_back("(");
        else if (bf[j]==')')
          tk.push_back(")");
        else if (!isspace(bf[j])) {
          string ss;
          while (!isspace(bf[j]) && bf[j]!=')' && bf[j]!='\0')
            ss+=bf[j++];
          tk.push_back(ss);
          if (bf[j]==')')
            tk.push_back(")");
          if (bf[j]=='\0')
            break;
        }
    }
    PRINT("Case #%d:\n", t);
    scanf("%d", &L);
    while (L--) {
      scanf("%s", bf);
      scanf("%d", &N);
      set<string> st;
      while (N--) {
        scanf("%s", bf);
        st.insert(bf);
      }
      PRINT("%.7lf\n", FindProbability(tk, 0, st, 1));
    }
  }
  return 0;
}

double FindProbability(const vector<string> &tk, int p, const set<string> &ft, double A) {
  assert(tk[p++]=="(");
  double n;
  sscanf(tk[p++].c_str(), "%lf", &n);
  A*=n;
  if (tk[p]==")")
    return A;
  else if (ft.count(tk[p++]))
    return FindProbability(tk, p, ft, A);
  else {
    int b=1;
    p++;
    while (b!=0) {
      if (tk[p]=="(")
        b++;
      if (tk[p]==")")
        b--;
      p++;
    }
    return FindProbability(tk, p, ft, A);
  }
}
