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

#define MAX 220

int n,x;
int s[MAX];
double res[MAX];


int count;
int id[MAX];
int xx;
double ave;

void init() {
}

void input() {
  scanf("%d",&n);
  int i;
  x=0;
  for(i=0;i<n;i++) {
    scanf("%d",s+i);
    x+=s[i];
    id[i]=i;
  }
}


int cmp(const void* a, const void* b) {
  return s[*(int*)a]-s[*(int*)b];
}

void output() {
  int i,j,k;

  qsort(id,n,sizeof(int),cmp);
  xx = x * 2;
  for(i=n-1;i>=0;i--) {
    xx -= s[id[i]];
    ave = (double)xx/(double)(i);
    if(s[id[i]]<ave) {
      xx += s[id[i]];
      break;
    }
    else
      res[id[i]]=0;
  }
  count = i+1;
  ave = (double)xx/(double)count;

  for(i=0;i<count;i++) {
    res[id[i]] = (ave - (double)s[id[i]]) / (double)x;
  }
  for(i=0;i<n;i++)
    printf("%lf ",res[i]*100);
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
