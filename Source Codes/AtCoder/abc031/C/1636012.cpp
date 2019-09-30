#include <cstdio>
#include <algorithm>

using namespace std;

int main(){

  int n;
  int a[50];

  scanf("%d", &n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int res = -99999;
  for(int i = 0; i < n; i++){
    int max_pa = -99999, max_pt = -99999;
    for(int j = 0; j < n; j++){
      if(i == j)
        continue;

      int t1 = min(i, j), t2 = max(i, j);

      int p_t = 0, p_a = 0;
      for(int k = 0; k <= t2 - t1; k++){
        if(k % 2 == 0){
          p_t += a[t1 + k];      
        }else{
          p_a += a[t1 + k];
        }
      }
      if(p_a > max_pa){
      //  printf("%d %d : %d %d\n", i, j, p_t, p_a);
        max_pa = p_a;
        max_pt = p_t;
      }
    }
    if(res < max_pt)
      res = max_pt;
  }
  printf("%d\n", res);
  return 0;
}