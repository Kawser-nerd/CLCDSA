
#include <stdio.h>

int map[10000001];

int main() {
  int T = 0;
  int C[2000];
  int used[2000];
  int N;
  int i;
  int sum;
  int min, minwhich;
  int cz, j;

  scanf("%d", &T);
  for(cz=1;cz<=T;cz++) {
    scanf("%d", &N);
    for(i=0;i<N;i++) scanf("%d", &C[i]);


      // apparently all pieces of candy must be used, so this problem is completely trivial....

#if 0
      // split C into 2 sets, everything ^ together should = 0
      // any two subsets could automatically be removed and added to the pile in any circumstance, except
      //   we want to maximize A's pile

      // make DP map, as soon as some entry matches with current, mark all as used
      // we sum it up later; B gets the smallest number in used; A gets everything else!


    while(1) {
      memset(map, -1, sizeof(map));
      for(i=0;i<N;i++) {
        if(!used[i]) {
          if(map[C[i]] != -1) break;

          for(j=0;j<=2000000;j++) {
            if(map[j] != -1 && map[j] != i) {
              map[j^C[i]] = i;
            }
          }
          map[C[i]] = i;
        }
      }
      if(i == N) break;  // no more fit

      used[i] = 1;
      i = C[i];
      while(i) {
        used[map[i]] = 1;
        i ^= C[map[i]];
      }
    }

    min = 2000000;
    for(i=0;i<N;i++) {
      if(used[i] && C[i] < min) {
        min = C[i];
        minwhich = i;
      }
    }

    sum = 0;
    for(i=0;i<N;i++) {
      if(used[i] && i != minwhich) sum += C[i];
    }

    printf("Case #%d: ", cz);
    if(sum) printf("%d\n", sum);
    else printf("NO\n");
#else

    sum = 0;
    for(i=0;i<N;i++) sum ^= C[i];
    if(sum != 0) {
      printf("Case #%d: NO\n", cz);
    } else {


      min = 2000000;
      sum = 0;
      for(i=0;i<N;i++) {
        sum += C[i];
        if(C[i] < min) {
          min = C[i];
          minwhich = i;
        }
      }

      sum -= min;

      printf("Case #%d: %d\n", cz, sum);
    }

#endif



  }

  return 0;
}
