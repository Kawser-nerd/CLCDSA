#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PEOPLE 100001  //??????

int a[PEOPLE];
int **b;        //??????????
int num;        //????
int d[PEOPLE];  //?????
int count[PEOPLE];
/*
void mergesort(int *array, int left, int right) {
  if(left+1<right){}
  int mid = (left+rught) / 2;
  mergesort(array, left, mid);
  mergesort(array, mid , right);
  merge(array, left, mid, right);
 }
 */
int int_cmp(const int *a, const int *b) {
  if (*a > *b)
    return (-1);
  else if (*a < *b)
    return (1);
  return (0);
}

int saiteikaisou(int n) {  //??????????????
  int max =
      -1;  //??????????????????????max???????????????????
  int i = 0;
  int *temp;
  temp = (int *)malloc(sizeof(int) * d[n]);
  int c = 0;  // max???????????

  if (b[n][i] == 0) {
    return 0;
  }

  while (b[n][i] != 0) {
    temp[i] = saiteikaisou(b[n][i]);
    i++;
  }
  qsort(temp, d[n], sizeof(int), (int(*)(const void*, const void*))int_cmp);

  for (i = 0; i < d[n]; i++) {
    if (max < i + temp[i] + 1) {
      max = i + temp[i] + 1;
    }
  }

  return max;
}

int main() {
  int i, j;

  int ans;

  for (i = 0; i < PEOPLE; i++) {  //???
    a[i] = 0;
    d[i] = 0;
    count[i] = 0;
  }

  scanf("%d", &num);
  for (i = 2; i <= num; i++) {
    scanf("%d", &a[i]);
    d[a[i]]++;
  }

  b = (int **)malloc(sizeof(int *) * (num + 1));  //???
  for (i = 0; i < num + 1; i++) {
    b[i] = (int *)calloc((d[i] + 2),
                         sizeof(int));  //???????????????
  }

  for (i = 2; i <= num; i++) {  //????????????
    b[a[i]][count[a[i]]] = i;
    count[a[i]]++;
  }

  ans = saiteikaisou(1);
  printf("%d", ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:68:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &num);
   ^
./Main.c:70:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^