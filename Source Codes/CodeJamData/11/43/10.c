#include <stdio.h>
#include <string.h>
typedef long long ll;
int ans[1001];
void fill(int x) {
  int y=x*x,i;
  while(y<1001) {
    for(i=y;i<1001;i++) ans[i]++;
    y*=x;
  }
}
void precalc() {
  int i;
  for(i=0;i<1001;i++) ans[i]=i>1;
  fill(2);
  fill(3);
  fill(5);
  fill(7);
  fill(11);
  fill(13);
  fill(17);
  fill(19);
  fill(23);
  fill(29);
  fill(31);
}
int main() {
  int N;
  int cases,caseno=1;
  precalc();
  scanf("%d",&cases);
  while(cases--) {
    scanf("%d",&N);
    printf("Case #%d: %d\n",caseno++,ans[N]);
  }
  return 0;
}
