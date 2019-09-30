#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ans;
int tc, cn, n, s, p, t[100];
//          0                   1                   2                     3
//          0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8  9  0
int  b[31]={0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10};
int sc[31]={0,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,0,0};

int main(void) {
  int i;
  scanf("%d", &tc);
  for(cn=1;cn<=tc;cn++) {
    scanf("%d%d%d", &n, &s, &p);
    for(ans=0,i=0;i<n;i++) {
      scanf("%d", &t[i]);
      if(b[t[i]]>=p)
	ans++;
      else if(s>0 && b[t[i]]+1==p && sc[t[i]]) {
	ans++;
	s--;
      }
    }
    printf("Case #%d: %d\n", cn, ans);
  }
  return 0;
}
