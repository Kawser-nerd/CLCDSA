#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

void run(void){
  int n,l;
  scanf("%d%d",&n,&l);
  int *x=(int *)calloc(n,sizeof(int));
  char *d=(char *)calloc(n,sizeof(char));
  int i;
  for(i=0;i<n;i++){
    char s[10];
    scanf("%d%s",x+i,s);
    d[i]=s[0];
  }
  int64 ans=0;
  int left=1;
  i=0;
  while(i<n){
    if(d[i]=='L'){
      ans+=x[i]-left;
      left++;i++;
      continue;
    }
    int a=1;
    i++;
    while(i<n && d[i]=='R'){
      ans+=(int64)a*(x[i]-x[i-1]-1);
      a++;
      i++;
    }
    if(i==n){
      ans+=(int64)a*(l-x[i-1]);
      break;
    }
    int b=1;
    int j=i+1;
    while(j<n && d[j]=='L'){
      ans+=x[j]-x[i]-b;
      j++;
      b++;
    }
    int m=x[i]-x[i-1]-1;
    if(a>b){
      ans+=(int64)a*m;
      left=x[i]+b-1;
    } else {
      ans+=(int64)b*m;
      left=x[i-1]+b-1;
    }
    i=j;
  }
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&l);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%s",x+i,s);
     ^