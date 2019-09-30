#include<stdio.h>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

#define BC 1000000007

int N;
long long n,m,X,Y,Z;
long long  data[500000];
long long c[500000];

void process() {
  int i,j;

  for (i=0;i<n;i++) {
    c[i] = 1;
  }

  for (i=0;i<n;i++) {
    for (j=0;j<i;j++) {
      if (data[i]>data[j]) {
	c[i] = (c[i] + c[j])%BC;
      }
    }
  }
}

long long getCount() {
  long long count = 0;
  int i;
  for (i=0;i<n;i++)
    count=(count+c[i])%BC;
  return count;
}

void main() {
  FILE *in=fopen(INPUT_FILE_NAME, "r");
  FILE *out=fopen(OUTPUT_FILE_NAME, "w");
  long long A[500000];
  int i,j;
  long long count;
 
  fscanf(in,"%d",&N);

  for (i=0;i<N;i++) {
    fscanf(in,"%lld %lld %lld %lld %lld",&n,&m,&X,&Y,&Z);

    for (j=0;j<m;j++)
      fscanf(in,"%lld",&A[j]);
    
    for (j=0;j<n;j++) {
      data[j] = A[j%m];
      A[j%m] = (X * A[j% m] + Y * (j + 1)) % Z;
    }

    process();
    count = getCount();

    fprintf(out,"Case #%d: %lld\n",i+1, count);
  }


}
