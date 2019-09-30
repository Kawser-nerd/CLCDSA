#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int len;
  int c;
} node;

int increment(node *s,int *top,int len,int m){
  int i;
  int sum=0;
  for(i=*top-1;i>=0;i--){
    if(s[i].c<m-1) break;
    sum+=s[i].len;
  }
  if(i<0) return 0;
  int c=s[i].c+1;
  if(s[i].len>1){
    s[i].len--;
    i++;
  }
  s[i]=(node){1,c};
  i++;
  if(sum>0){
    s[i]=(node){sum,0};
    i++;
  }
  *top=i;
  return 1;
}

int can(const int m,const int *a,const int n){
  static node *s=NULL;
  if(s==NULL) s=(node *)calloc(n,sizeof(node));
  int top=0;
  s[top++]=(node){a[0],0};
  int len=a[0];
  int i;
  for(i=1;i<n;i++){
    if(len<a[i]){
      s[top++]=(node){a[i]-len,0};
      len=a[i];
      continue;
    }
    while(len-s[top-1].len>=a[i]){
      len-=s[top-1].len;
      top--;
    }
    s[top-1]=(node){s[top-1].len-(len-a[i]),s[top-1].c};
    len=a[i];
    if(!increment(s,&top,len,m)) return 0;
  }
  return 1;
}

void run(void){
  int n;
  scanf("%d",&n);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int l=0;
  int r=n;
  while(r-l>1){
    int m=(l+r)/2;
    if(can(m,a,n)){
      r=m;
    } else {
      l=m;
    }
  }
  printf("%d\n",r);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:58:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:61:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^