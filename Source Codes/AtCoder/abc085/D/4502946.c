#include <stdio.h>
#include <stdlib.h>

int compar(const int *val1, const int *val2) {//??????
    if ( *val1 > *val2 ) {
        return -1;
    } else if ( *val1 == * val2 ) {
        return 0;
    } else {
        return 1;
    }
}

int main(){
  int n,hitpoint;
  scanf("%d %d",&n,&hitpoint);
  int a[n],b[n];
  for(int i = 0; i < n; ++i) scanf("%d %d",&a[i],&b[i]);
  qsort(a, n, sizeof(int),(int (*)(const void *, const void *))compar);
  qsort(b, n, sizeof(int),(int (*)(const void *, const void *))compar);
  int damage, damage_b = 0;
  int num_attack = 0, num_attack_a;
  int left_point;
  int answer = 1000000000;
  for(int i = 0; i < n; ++i){
    damage_b += b[i];//b[0], .. ,b[i],a[0], .. ,a[0]
    damage = damage_b;
    num_attack = i + 1;
    left_point = hitpoint - damage;
    if(left_point > 0) num_attack_a = (left_point - 1)/a[0] + 1;//ceil
    else num_attack_a = 0;
    num_attack += num_attack_a;
    if(num_attack < answer) answer = num_attack;
    if(num_attack <= 0) break;//b???ok????
  }
  printf("%d\n",answer);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&hitpoint);
   ^
./Main.c:18:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0; i < n; ++i) scanf("%d %d",&a[i],&b[i]);
                              ^