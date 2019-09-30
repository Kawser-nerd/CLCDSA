#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<list>

using namespace std;

const int MAX=70000;

int C,D,N;

char comi[MAX];
char oppi[MAX];
char com[36][4];
char opp[28][3];
char input[101];

void build_comi(void)
{
  int i;
  for(i=0;i<MAX;++i){
    comi[i] = '\0';
  }
  for(i=0;i<C;++i){
    int index1 = com[i][0]*256 + com[i][1];
    int index2 = com[i][1]*256 + com[i][0];
    char result = com[i][2];

    comi[index1] = result;
    comi[index2] = result;
  }
}

void build_oppi(void)
{
  int i;
  for(i=0;i<MAX;++i){
    oppi[i] = 0;
  }
  for(i=0;i<D;++i){
    int index1 = opp[i][0]*256 + opp[i][1];
    int index2 = opp[i][1]*256 + opp[i][0];

    oppi[index1] = 1;
    oppi[index2] = 1;
  }
}

char test_comi(char a, char b)
{
  return comi[a*256+b];
}

bool test_oppi(char a, char b)
{
  return oppi[a*256+b];
}

void do_case(void)
{
  int i,j;

  scanf("%d", &C);
  for(i=0;i<C;++i){
    scanf("%s", com[i]);
  }
  scanf("%d", &D);
  for(i=0;i<D;++i){
    scanf("%s", opp[i]);
  }
  scanf("%d", &N);
  scanf("%s", input);

  build_comi();
  build_oppi();

  j=-1;
  char result[100];
  for(i=0;i<N;++i){
    result[++j]=input[i];
    char com_res = '\0';
    if(j == 0) continue;
    if((com_res = test_comi(result[j-1], result[j])) != '\0'){
      result[--j] = com_res;continue;
    }

    for(int k=0;k<j;++k){
      if(test_oppi(result[k], result[j])) {j = -1;break;}
    }
  }
  if(j < 0) {
    printf("[]\n");
    return;
  }

  printf("[");

  for(i=0;i<=j-1;++i) printf("%c, ", result[i]);
  printf("%c]\n", result[j]);
  return;
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
