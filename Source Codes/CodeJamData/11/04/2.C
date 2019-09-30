#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>

using namespace std;

int a[1000];

void do_case(void)
{
  int N;
  scanf("%d", &N);

  int i;
  int correct=0;
  for(i=0;i<N;++i){
    scanf("%d", &a[i]);
    if(a[i] == i+1) ++correct;
  }

  printf("%d.000000\n", N-correct);
}

int main()
{
  freopen("input.data", "r", stdin);
  //freopen("output.data", "r", stdout);

  int cases;
  scanf("%d\n", &cases);
  int i = 1;
  do{
    printf("Case #%d: ", i);
    do_case();
  }while(++i <= cases);

  return 0;
}
