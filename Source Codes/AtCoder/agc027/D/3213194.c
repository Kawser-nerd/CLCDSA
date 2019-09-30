#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define POS(i,j) ((i)*n+(j))

void sieve(char *p,int n){
  int i,j;
  for(i=2;i<=n;i++) p[i]=1;
  p[0]=p[1]=0;
  for(i=2;i*i<=n;i++){
    if(!p[i]) continue;
    for(j=i*i;j<=n;j+=i) p[j]=0;
  }
  return;
}

char *buf=NULL;
int pointer=0;
inline void print(char c){
  buf[pointer++]=c;
}

inline void printInt(int64 n){
  char s[20];
  int p=0;
  while(n>0){
    s[p++]='0'+n%10;
    n/=10;
  }
  while(p>0) print(s[--p]);
}

void run(void){
  const int n=500;
  char *p=(char *)malloc(sizeof(char)*5001);
  sieve(p,5000);
  int *l=(int *)malloc(sizeof(int)*(n+1));
  int *r=(int *)malloc(sizeof(int)*(n+1));
  int lp=0;
  int rp=0;
  int i=2;
  while(lp<n+1){
    l[lp++]=i++;
  }
  while(rp<n+1){
    if(p[i]) r[rp++]=i;
    i++;
  }
  int64 *board=(int64 *)malloc(sizeof(int64)*n*n);
  int j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if((i+j)%2==0){
	board[POS(i,j)]=l[(i+j)/2]*r[((n-i)+j)/2];
      } else {
	int64 lcm=(int64)l[(i+j)/2]*l[(i+j)/2+1]*r[((n-i)+j)/2]*r[((n-i)+j)/2+1];
	board[POS(i,j)]=lcm+1;
      }
    }
  }
  buf=(char *)calloc(2500000,sizeof(char));
  int m;
  scanf("%d",&m);
  for(i=0;i<m;i++){
    printInt(board[POS(i,0)]);
    for(j=1;j<m;j++){
      print(' ');
      printInt(board[POS(i,j)]);
    }
    print('\n');
  }
  puts(buf);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:65:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m);
   ^