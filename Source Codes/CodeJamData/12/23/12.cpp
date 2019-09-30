#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <map>
#include <ctime>
#include <vector>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  srand(unsigned(time(0)));

  for(int z = 1; z <= t; z++) {
    int n;
    scanf("%d", &n);

    long long num[500];
    for(int i = 0; i < n; i++)
      scanf("%lld", &num[i]);

    long long msk[2] = {-1, -1};
    for(int tr = 0; ; tr++) {
      fprintf(stderr, "Test case %d: try %d\n", z, tr);

      random_shuffle(num, num+n);
      vector<pair<long long, long long> > v;

      for(int mask = 1; mask < (1<<20); mask++) {
	long long sum = 0;
	for(int i = 0; i < 20; i++)
	  if(mask & (1<<i))
	    sum += num[i];

	v.push_back(make_pair(sum, mask));
      }

      if(n == 500) {
	for(int mask = 1; mask < (1<<20); mask++) {
	  long long sum = 0;
	  for(int i = 0; i < 20; i++)
	    if(mask & (1<<i))
	      sum += num[i+20];
	  
	  v.push_back(make_pair(sum, ((long long)mask)<<20));
	}
      }

      sort(v.begin(), v.end());
      for(unsigned int i = 1; i < v.size(); i++) {
	if(v[i].first == v[i-1].first) {
	  msk[0] = v[i].second;
	  msk[1] = v[i-1].second;
	  break;
	}
      }
	
      if(n == 20 || msk[0] != -1)
	break;
    }
    
    printf("Case #%d:\n", z);
    if(msk[0] == -1) {
      assert(n == 20);
      printf("Impossible");
    } else {
      fprintf(stderr, "%lld %lld", msk[0], msk[1]);

      for(int b = 0; b < 2; b++) {
	bool first = true;
	
	for(int i = 0; i < 40; i++)
	  if(msk[b] & (1LL<<i)) {
	    if(!first) printf(" ");
	    first = false;
	    printf("%lld", num[i]);
	  }

	printf("\n");
      }
    }
  }
}
