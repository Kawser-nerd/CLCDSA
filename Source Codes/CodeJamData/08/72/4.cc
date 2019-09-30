#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>
#include <cmath>
using namespace std;

typedef long long ii;

int N;
int S[10001];
int c[30];
int start[4096];

int _(int x) {
  while (x < 0) x += 10007;
  while (x >= 10007) x -= 10007;
  return x;
}

int main() {
  int T; cin >> T;
  for (int it = 1; it <= T; it++) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> S[i];

    memset(c, -1, sizeof(c));
    memset(start, 1, sizeof(start));
    
    int maxbits = 0;
    while ((1 << maxbits) <= N) maxbits++;
    //    printf("N = %d, maxbits = %d, 2^maxbits = %d\n", N,maxbits, 1<<maxbits);

    for (int i = 0; i < maxbits; i++) {
      int leap = 1 << i;

      for (int j = 0; j < 2*leap; j++) {
	int diff = -50000;        // sentinel
	bool okay = 1;

	for (int k = j+leap; k < N; k += 2*leap) {
	  int curdiff = _(S[k] - S[k-leap]);
	  if (diff == -50000) {diff = curdiff;}
	  else {
	    if (diff != curdiff) {
	      okay = 0;
	      break;
	    }
	  }
	}

	if (!okay) {
	  // we know something about the start; it cannot fall with this start offset
	  // or any others you can get with any higher bits
	  //	  printf("bit %d: eliminating offset %d\n", i, j);
	  for (int k = j; k < (1 << maxbits); k += 2*leap)
	    start[k] = 0;
	}
      }
    }

    //    for (int i = 0; i < (1 << maxbits); i++) {
    //      printf("%d: %d\n", i, start[i]);
    //    }

    // now, we have isolated all inconsistencies
    // see if we can identify specific values of C_k
    for (int i = 0; i < maxbits; i++) {
      vector<int> okay;

      int jump = 1 << i;
      // if only one works, then we know
      for (int j = 0; j < 2*jump; j++) {
	if (start[j]) okay.push_back(j);
      }

      int cval = -1;
      bool unknown = 0;

      for (int j = 0; j < okay.size(); j++) {
	int idx1 = (2*jump - okay[j])%(2*jump);
	int idx2 = idx1 + jump;
	//	printf("bit %d: checking idx %d\n", i, idx1);

	if (idx2 < N) {
	  int cv = _(S[idx2] - S[idx1]);
	  if (cval == -1) {cval = cv;}
	  else if (cval != cv) {
	    cval = -1;
	    unknown = 1;
	  }
	}
	else {
	  //	  unknown = 1;
	}
      }

      if (!unknown && cval != -1) {
	c[i] = cval;
      }
    }

    //    for (int i = 0; i < (1 << maxbits); i++) {
    //      printf("%d: %d\n", i, c[i]);
    //    }

    bool conflict = 0;
    int answer  = -1;
    for (int i = 0; i < (1 << maxbits); i++) {
      if (start[i]) {
	//	printf("looking at start = %d\n", i);

	int lastidx = i + N;

	bool anybit = 0;
	for (int j = 0; j < maxbits; j++) {
	  if (lastidx & (1 << j)) {
	    int other = lastidx - (1 << j);
	    if (other >= i && c[j] != -1) {
	      anybit = 1;
	      int temp = _(S[other-i] + c[j]);
	      if (answer == -1) {
		answer = temp;
	      }
	      else {
		if (answer != temp) {
		  conflict = 1;
		  answer = -1;
		}
	      }
	    }
	  }
	}

	if (!anybit) {
	  //	  printf("no bit found for start = %d, lastidx = %d\n", i, lastidx);
	  conflict = 1;
	}
      }
    }

    printf("Case #%d: ", it);
    if (conflict || answer == -1) printf("UNKNOWN\n");
    else printf("%d\n", answer);
  }
}
