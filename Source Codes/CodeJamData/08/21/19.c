#include <stdio.h>
#include <string.h>

void freadline(char *s, FILE *f) {
  int i=0;
  while((s[i++] = fgetc(f)) != '\n');
  
  s[i-1]='\0';
  return;
}

void freadword(char *s, FILE *f) {
  int i=0;
  char c='k';

  while(c != ' ' && c != '\n' && c != '\t' && c != '\r') {
    c=fgetc(f);
    s[i++]=c;
  }
  
  s[i-1]='\0';
  return;
}

int main(int argc, char **argv) {
  char line[255];
  char cptr[10];
  FILE *f;
  int cases=0, num=0;
  int i,j,k,l; // temp
  long long int n, A, B, C, D, x0, y0, M;
  int x[100000], y[100000];
  long long int nt=0;

  f=fopen(argv[1], "r");
  
  freadline(line, f);
  cases=atoi(line);

  for(i=0; i<cases; i++) {
    nt=0;
    freadword(cptr, f);
    n=atoi(cptr);
    freadword(cptr, f);
    A=atoi(cptr);
    freadword(cptr, f);
    B=atoi(cptr);
    freadword(cptr, f);
    C=atoi(cptr);
    freadword(cptr, f);
    D=atoi(cptr);
    freadword(cptr, f);
    x0=atoi(cptr);
    freadword(cptr, f);
    y0=atoi(cptr);
    freadword(cptr, f);
    M=atoi(cptr);

    x[0]=x0;
    y[0]=y0;
    //    printf("%d %d\n", x[0], y[0]);
    for(l=1; l<n;l++) {
      x[l]=(A*x[l-1]+B)%M;
      y[l]=(C*y[l-1]+D)%M;
      //      printf("%d %d\n", x[l], y[l]);
    }
    
    for(j=0; j<n; j++) {
      for(k=(j+1); k<n; k++) {
	for(l=(k+1); l<n; l++) {
	  if(((x[j]+x[k]+x[l])%3 == 0) && ((y[j]+y[k]+y[l])%3 == 0) && ((j!=k) && (k!=l) && (l!=j))) {
	    nt++;
	    //	    printf("%d %d %d\n", j, k, l);
	  }
	}
      }
    }
    printf("Case #%d: %lld\n", (i+1), nt);
  }
}
