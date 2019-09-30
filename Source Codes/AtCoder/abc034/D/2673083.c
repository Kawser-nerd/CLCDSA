#include <stdio.h>

int n, k;
int W[1000];
double P[1000];

double kth(int k, double t){
  double lb, ub;
  int i, j;
  lb = -1000000001;
  ub = -lb;
  for(j=0;j<30;j++){
    double m = (lb + ub) / 2;
    int c = 0;
    for(i=0;i<n;i++) c += (P[i] - t) * W[i] >= m;
    if(c >= k) lb = m;
    else ub = m;
  }
  return lb;
}

int p(double x){
  int i;
  double c = 0;
  double z = kth(k, x);
  for(i=0;i<n;i++) if((P[i] - x) * W[i] >= z) c += (P[i] - x) * W[i];
  return c >= 0;
}

int main(){
  int i;
  double lb, ub;
  scanf("%d%d", &n, &k);
  for(i=0;i<n;i++){
    int p;
    scanf("%d%d", W+i, &p);
    P[i] = p * 0.01;
  }

  lb = 0;
  ub = 1;

  for(i=0;i<30;i++){
    double m = (lb + ub) / 2;
    if(p(m)) lb = m;
    else ub = m;
  }

  printf("%f\n", lb*100);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &n, &k);
   ^
./Main.c:36:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", W+i, &p);
     ^