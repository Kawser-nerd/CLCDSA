#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

typedef struct sequence{
  char s[6];
} seq;

int cmp(const void *a,const void *b){
  char *p=((seq *)a)->s;
  char *q=((seq *)b)->s;
  int i=0;
  while(p[i]!='\0' && q[i]!='\0'){
    if(p[i]!=q[i]) return (int)(p[i]-q[i]);
    i++;
  }
  if(p[i]=='\0' && q[i]=='\0') return 0;
  return p[i]=='\0'?-1:1;
}

void run(void){
  char s[5001];
  scanf("%s",s);
  int len=0;
  while(s[len]!='\0') len++;
  int k;
  scanf("%d",&k);
  seq *array=(seq *)malloc(sizeof(seq)*5*len);
  int alen=0;
  int i;
  for(i=1;i<=k;i++){
    int j;
    for(j=0;j+i-1<len;j++){
      int l;
      for(l=0;l<i;l++){
	array[alen].s[l]=s[j+l];
      }
      array[alen].s[l]='\0';
      alen++;
    }
  }
  qsort(array,alen,sizeof(seq),cmp);
  int cnt=0;
  i=0;
  seq t;
  while(cnt<k){
    t=array[i];
    cnt++;
    while(i<alen && cmp(&array[i],&t)==0) i++;
  }
  printf("%s\n",t.s);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^