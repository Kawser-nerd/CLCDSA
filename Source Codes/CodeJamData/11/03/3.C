#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>

using namespace std;

unsigned long value[1000];

void do_case(void)
{
  int N;
  scanf("%d", &N);

  int i;
  for(i=0;i<N;++i){
    scanf("%lu", &value[i]);
  }

  unsigned long xorsum=0;
  unsigned long min=1000000;
  unsigned long sum = 0;
  for(i=0;i<N;++i){
    xorsum ^= value[i];
    if(min > value[i]) min = value[i];
    sum += value[i];
  }
  if(xorsum != 0){
    printf("NO\n");
    return;
  }

  printf("%lu\n", sum - min);
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
