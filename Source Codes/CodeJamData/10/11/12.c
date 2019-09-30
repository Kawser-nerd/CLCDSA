#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void chomp(char *s) {
  char *p;
  p = s + strlen(s) - 1;
  while(p!=s && (*p=='\n' || *p=='\r')) {
    *p = 0;
    p--;
  }
}

int t,n,k,c;
char b[50*50];

void gravity(int row) {
  char proper[50];
  int i,pn=0;

  for(i=0;i<n;i++)
    if (b[i+row*n]!='.') {
      proper[pn] = b[i+row*n];
      pn++;
    }

  proper[pn]=0;
  memset(&b[row*n],'.',n);
  for(i=0;i<pn;i++)
    b[n-pn+i + row*n] = proper[i];
}

int check(char c) {
  int i,j,x;
  int h,v,d1,d2;

  for(i=0;i<n;i++)
    for(j=0;j<n;j++) {
      if (b[i + j*n] != c) continue;
      if (k==1) return 1;

      h=v=d1=d2=1;
      for(x=1;x<k;x++) {
	if (i+x < n)
	  if (b[i+x + j*n] == c) h++;
	if (h==k) return 1;
	if (j+x < n)
	  if (b[i + (j+x)*n] == c) v++;
	if (v==k) return 1;
	if (j+x < n && i+x < n)
	  if (b[i+x + (j+x)*n] == c) d1++;
	if (d1==k) return 1;
	if (j+x < n && i-x >=0)
	  if (b[i-x + (j+x)*n] == c) d2++;
	if (d2==k) return 1;
      }
    }
  return 0;
}

void pboard() {

  int i,j;

  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      printf("%c",b[j+i*n]);
    }
    printf("\n");
  }
}

int main(int argc, char **argv) {
  int i,j,R,B;
  char s[512];

  scanf("%d\n",&t);

  for(c=1;c<=t;c++) {
    scanf("%d %d\n",&n,&k);
    
    for(i=0;i<n;i++) {
      fgets(s,512,stdin);
      for(j=0;j<n;j++)
	b[j+i*n] = s[j];
    }

    for(i=0;i<n;i++)
      gravity(i);

    //pboard();

    R = check('R');
    B = check('B');

    printf("Case #%d: ",c);
    if (R && B)
      printf("Both\n");
    else if (R && !B)
      printf("Red\n");
    else if (!R && B)
      printf("Blue\n");
    else
      printf("Neither\n");
  }

  return 0;
}
