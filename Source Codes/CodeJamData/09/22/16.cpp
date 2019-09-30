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

int main() {
  int i, j, t, T;
  scanf("%d", &T);
  for (t=1; t<=T; t++) {
    scanf("%s", bf);
    for (i=0; bf[i]; i++);
    vector<char> vr(1, bf[i-1]);
    for (i-=2; i>=0; i--) {
      vr.push_back(bf[i]);
      if (bf[i]<bf[i+1])
        break;
    }
    PRINT("Case #%d: ", t);
    sort(vr.begin(), vr.end());
    if (i<0) {
      for (j=0; vr[j]=='0'; j++);
      PRINT("%c0", vr[j]);
      vr[j]='_';
    }
    else {
      for (j=0; vr[j]<=bf[i]; j++);
      bf[i]='\0';
      PRINT("%s", bf);
      PRINT("%c", vr[j]);
      vr[j]='_';
    }
    for (j=0; j<SIZE(vr); j++)
      if (vr[j]!='_')
        PRINT("%c", vr[j]);
    PRINT("\n");      
  }
  return 0;
}
