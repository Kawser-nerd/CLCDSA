#include <stdio.h>
#include <math.h>

double max(double a,double b){
  if(a > b){
    return a;
  }
  return b;
}

double dist(double a,double b){
  return a*a+b*b;
}

int main(void){
  int N;
  scanf("%d",&N);

  long ax[N],ay[N];
  long bx[N],by[N];

  double gax = 0,gay = 0;
  for(int i = 0;i < N;i++){
    scanf("%ld%ld",&ax[i],&ay[i]);
    gax += ax[i];
    gay += ay[i];
  }
  gax /= (double)N; gay /= (double)N;

  double maxdista = 0;
  for(int i = 0;i < N;i++){
    maxdista = max(maxdista,dist((double)ax[i]-gax,(double)ay[i]-gay));
  }

  double gbx = 0,gby = 0;
  for(int i = 0;i < N;i++){
    scanf("%ld%ld",&bx[i],&by[i]);
    gbx += bx[i];
    gby += by[i];
  }
  gbx /= (double)N; gby /= (double)N;

  double maxdistb = 0;
  for(int i = 0;i < N;i++){
    maxdistb = max(maxdistb,dist((double)bx[i]-gbx,(double)by[i]-gby));
  }

  printf("%.9lf\n",sqrt(maxdistb/maxdista));

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld",&ax[i],&ay[i]);
     ^
./Main.c:37:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld",&bx[i],&by[i]);
     ^