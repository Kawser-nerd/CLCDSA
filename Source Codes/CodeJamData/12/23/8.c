#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define dprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#define swap(a,b,c) { c=a;a=b;b=c; }
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

typedef long long ll;

int ncase,icase;

void flush()     { int c; while((c=getchar())!='\n'&&c!=EOF); }
int  printcase() { printf("Case #%d: ", icase); }
void nline()     { putchar('\n'); }
void sp()        { putchar(' '); }

//////////////////////////////////

//////////////////////////////////

#define MAX 510
#define MAX2 (1<<20)

int n;
int s[MAX];
int sum[MAX2];

void init() {
}

void input() {
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++) {
    scanf("%d",s+i);
  }
}



void output() {
  int i,j,k,l;

  ll mm = 1<<n;
  int f=0;
  for(i=0;i<mm;i++) {
    j = i;
    k = 0;
    sum[i]=0;
    while(j>0) {
      if(j&1) {
	sum[i]+=s[k];
      }
      k++;
      j>>=1;
    }
    for(j=0;j<i;j++) {
      if(sum[i]==sum[j]) {
	f=1;
	
	k=0;
	l=i;
	nline();
	while(l>0) {
	  if(l&1) {
	    printf("%d ",s[k]);
	  }
	  k++;
	  l>>=1;
	}
	k=0;
	l=j;
	nline();
	while(l>0) {
	  if(l&1) {
	    printf("%d ",s[k]);
	  }
	  k++;
	  l>>=1;
	}
      }
    }
    if(f)
      break;
  }
  if(!f)
    printf("Impossible");
}

void solve() {
  printcase();
  input();
  output();
  nline();
}

int main(int argc, char** argv) {
  if(argc>1)
    freopen(argv[1],"r",stdin);
  if(argc>2)
    freopen(argv[2],"w",stdout);

  init();

  scanf("%d",&ncase); flush();
  for(icase=1;icase<=ncase;++icase)
    solve();
}
