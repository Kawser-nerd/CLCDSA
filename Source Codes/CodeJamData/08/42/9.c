#include<stdio.h>
#include<math.h>

#define OUTSTREAM stdout

int C,N,M,A;
int x[3],y[3];

int factors[100][2][10001];
int nfactors[10001];
 
int rprime (int x,int y) {
  if (y ==0)
    return x;
  return rprime(y, x%y);
}

void getfactors() {
  int i,j;
  int s;
  int f1,f2;

  for (i=0;i<=10000;i++)
    nfactors[i]=0;

  for (i=1;i<=10000;i++)
    for (j=1;j<=100;j++) {
      if (j*j > i)
	break;

      f1 = j;
      f2 = sqrt(i*i-f1*f1);
      if (f1*f1 + f2*f2 != i)
	continue;

      factors[nfactors[s]++][0][s] = f1;
      factors[nfactors[s]++][1][s] = f2;
    }

  return;
}

int getMin(int a,int b, int c) {
  int min=a<b?a:b;
  if (min<c)
    return min;
  else
    return c;
}

int proc() {
  int tx,ty,maxA=sqrt(A);
  int x1,x2,y1,y2;
  int dx, dy, gcd, ulen, f; 
  int i,j;
  int mx = 0, my = 0;

  for (tx=1;tx<=sqrt(A);tx++) {
    if (A%tx)
      continue;

    ty = A/tx;

    for (i=0;x<nfactors[tx];i++) {
      x1 = factors[i][0][tx];
      y1 = factors[i][1][tx];

      gcd = rprime(x1,y1);
      dx = (-1) * (y1/gcd);
      dy = x1 / gcd;

      ulen = dx * dx + dy * dy;
      if (ty % ulen)
	continue;
      f = ty / ulen;
      x2 = dx * f;
      y2 = dy * f;

      
    }
  }


  
  return -1;
}

void main() {
  FILE *in=fopen("input.txt","r");
  FILE *out=fopen("output.txt","w");
  long i,j;
  long min;

  getfactors();
  
  fscanf(in,"%d",&C);
  for (i=0;i<C;i++) {
    fscanf(in,"%d %d %d",&N,&M,&A);

    min=proc();

    if (min == -1)
      fprintf(OUTSTREAM,"Case #%ld: IMPOSSIBLE\n",i+1);
    else
      fprintf(OUTSTREAM,"Case #%ld: %d %d %d %d %d %d\n",i+1, x[0], y[0], x[1], y[1], x[2], y[2]);
  }
}
