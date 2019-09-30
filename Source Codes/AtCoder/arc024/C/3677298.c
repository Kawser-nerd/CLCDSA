#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct charcount{
  int cnt[26];
  int l;
} node;

int cmp(const void *a,const void *b){
  int *x=((node *)a)->cnt;
  int *y=((node *)b)->cnt;
  int i;
  for(i=0;i<26;i++) if(x[i]!=y[i]) return x[i]-y[i];
  return 0;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  char *s=(char *)calloc(n+1,sizeof(char));
  scanf("%s",s);
  node *array=(node *)calloc(n+1-k,sizeof(node));
  node t;
  memset(&t,0,sizeof(node));
  int i;
  for(i=0;i<k-1;i++) t.cnt[s[i]-'a']++;
  for(i=k-1;i<n;i++){
    t.cnt[s[i]-'a']++;
    t.l=i+1-k;
    array[i+1-k]=t;
    t.cnt[s[i+1-k]-'a']--;
  }
  qsort(array,n+1-k,sizeof(node),cmp);
  int find=0;
  i=0;
  while(i<n+1-k){
    int min=array[i].l;
    int max=array[i].l;
    int j=i+1;
    while(j<n+1-k && cmp(array+i,array+j)==0){
      if(min>array[j].l) min=array[j].l;
      if(max<array[j].l) max=array[j].l;
      j++;
    }
    if(max-min>=k) find=1;
    i=j;
  }
  printf("%s\n",find?"YES":"NO");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^