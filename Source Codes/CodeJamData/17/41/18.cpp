#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl
#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

// int brute(int cnt[4]) {
//   vector <int> T;
//   REP(i, 4) 
//     REP(j, cnt[i])
//     T.push_back(i);

//   int rje = 0;
//   do {
//     int val = 0, ost = 0;
//     for (auto it : T){
//       if (!ost) val++;
//       ost = (ost + it) % 4;
//     }

//     rje = max(rje, val);
//   } while(next_permutation(T.begin(), T.end()));

//   return rje;
// }
  
int eval(vector <int> &V, int p) {
  int ret = 0, os = 0;
  for (auto it : V) {
    if (!os) ret++;
    os = (os + it) % p;
  }

  return ret;
}

int main()
{
  // REP(i, 1000) {
  //   int cnt[4];

  //   REP(j, 4) cnt[j] = rand() % 3 + 1;
  //   //    REP(j, 4) TRACE(j _ cnt[j]);

  //   int br = brute(cnt);

  //   vector <int> V;
  //   for (; cnt[0]; cnt[0]--)
  //     V.push_back(0);
    
  //   for (; cnt[2] >= 2; cnt[2] -= 2) {
  //     V.push_back(2);
  //     V.push_back(2);
  //   }

  //   for (; cnt[1] && cnt[3]; cnt[1]--, cnt[3]--) {
  //     V.push_back(1);
  //     V.push_back(3);
  //   }

  //   for (; cnt[2]; cnt[2]--)
  //     V.push_back(2);
  //   for (; cnt[1]; cnt[1]--)
  //     V.push_back(1);
  //   for (; cnt[3]; cnt[3]--)
  //     V.push_back(3);

  //   int rje = eval(V, 4);
  //   assert(br == rje);
  // }

  // int rje = cnt[0];
  // if (cnt[1] || cnt[2] || cnt[3]) rje++;
    
  // if (cnt[2] > 1) {
  //   rje += (cnt[2] - 2) / 2;
  //   cnt[2] %= 2;
  //   if (cnt[1] || cnt[2] || cnt[3]) rje++;
  // }
  // TRACE(rje);

  // if (cnt[1] && cnt[3]) {
  //   rje += min(cnt[1], cnt[3]) - 1;
  //   int mn = min(cnt[1], cnt[3]);
  //   cnt[1] -= mn; cnt[3] -= mn;
  // }
      
  // if (cnt[1] || cnt[2] || cnt[3]) rje++;
   
  // TRACE(br _ rje);
  // assert(rje == br);

  // TRACE(i);

  int brt;
  scanf("%d", &brt);
  
  FOR(tt, 1, brt+1) {
    int n, p;
    scanf("%d%d", &n, &p);
    int cnt[p];
    memset(cnt, 0, sizeof cnt);

    REP(i, n) {
      int x;
      scanf("%d", &x);
      cnt[x%p]++;
    }

    int rje = cnt[0];
    if (p == 2) rje += (cnt[1]+1) / 2;
    else if (p == 3) {
      if (cnt[1] + cnt[2]) {
	rje += min(cnt[1], cnt[2]);
	rje += (max(cnt[1], cnt[2]) - min(cnt[1], cnt[2]) + 2) / 3;
      }
    }
    else {
      // int br = brute(cnt);
      // TRACE(br);


      vector <int> V;
      for (; cnt[0]; cnt[0]--)
	V.push_back(0);
	  
      for (; cnt[2] >= 2; cnt[2] -= 2) {
	V.push_back(2);
	V.push_back(2);
      }

      for (; cnt[1] && cnt[3]; cnt[1]--, cnt[3]--) {
	V.push_back(1);
	V.push_back(3);
      }

      for (; cnt[2]; cnt[2]--)
	V.push_back(2);
      for (; cnt[1]; cnt[1]--)
	V.push_back(1);
      for (; cnt[3]; cnt[3]--)
	V.push_back(3);

      rje = eval(V, 4);
    }

    //    TRACE(br);
    printf("Case #%d: %d\n", tt, rje);
  }  

  return 0;
}
