#include <stdio.h>
#include <stdlib.h>


typedef struct {
  double speed, length;
  int taken;
} Walkway;

double S, R, t;
int T, X, N, nopath;
Walkway paths[1002];

void make_run(int index) {
  
  double temp = paths[index].length/(paths[index].speed+R-S);

  if(temp>=t) {
    double dist_run = t*(paths[index].speed+R-S);
    double total_time = t+(paths[index].length - dist_run)/(paths[index].speed);
    t = 0.0;
    paths[index].speed = paths[index].length / total_time;
  }
  else {
    paths[index].speed += (R-S);
    t-= paths[index].length/paths[index].speed;
  }
  paths[index].taken = 1;
  
}

void apply_filter() {

  double min = 100000000.0;
  int min_index = -1, i, j;
  for(i=0; i<N; i++) {
    if(paths[i].speed<min && paths[i].length && !paths[i].taken) {
      min = paths[i].speed;
      min_index = i;
    }
  }

  make_run(min_index);

}

double get_time() {

  int i;
  double ans = 0;
  
  for(i=0; i<N; i++) {
    //printf("l = %.5lf, s = %.5lf, t = %d\n", paths[i].length, paths[i].speed, paths[i].taken);
    ans +=  paths[i].length/paths[i].speed;
  }

  return ans;
}

int all_taken() {
  int i;
  for(i=0; i<N; i++) 
    if(paths[i].taken==0)
      return 0;
  return 1;
}

int main() {

  scanf("%d", &T);

  int i,j,k;

  for(i=1; i<=T; i++) {
    scanf("%d", &X);
    scanf("%lf", &S);
    scanf("%lf", &R);
    scanf("%lf", &t);
    scanf("%d", &N);
    nopath = 0;
    int last;
    for(j=0; j<N; j++) {
      paths[j].taken = 0;
      int t1, t2;
      scanf("%d %d %lf", &t1, &t2, &paths[j].speed);
      paths[j].speed += S;
      paths[j].length = ((double)t2-t1);
      if(j==0) 
	nopath = t1;
      else
	nopath = nopath + (t1-last);
      last = t2;
    }
    nopath = nopath + (X-last);
    if(nopath) {
      paths[N++].length = ((double)nopath);
      paths[N-1].speed = S;
      paths[N-1].taken = 0;
    }
    while(t>0.0000000 && !all_taken())
      apply_filter();

    printf("Case #%d: %.8lf\n", i, get_time());
    
  }

  return 0;

}
