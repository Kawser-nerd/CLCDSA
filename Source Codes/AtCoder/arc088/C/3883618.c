#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int int64;

typedef struct vector{
  int *a;
  int len;
  int maxLen;
} vec;

vec* newVector(void){
  vec *v=(vec *)calloc(1,sizeof(vec));
  v->a=NULL;
  v->len=0;
  v->maxLen=0;
  return v;
}

void push_back(vec *v,int x){
  if(v->len==v->maxLen){
    v->maxLen=2*v->maxLen+1;
    v->a=realloc(v->a,sizeof(int)*v->maxLen);
  }
  v->a[v->len++]=x;
}

int64 calcInversion(int *a,int n,int *tmp){
  if(n<=1) return 0;
  int m=n/2;
  int64 res=calcInversion(a,m,tmp)+calcInversion(a+m,n-m,tmp);
  memcpy(tmp,a,sizeof(int)*m);
  int i=0;
  int j=m;
  int k=0;
  while(i<m && j<n){
    if(tmp[i]<=a[j]){
      a[k++]=tmp[i++];
    } else {
      res+=m-i;
      a[k++]=a[j++];
    }
  }
  memcpy(a+k,tmp+i,sizeof(int)*(m-i));
  return res;
}

int64 calc(char *s,int n,vec **v){
  int64 ans=0;
  int cnt[26]={0};
  int back=0;
  int mid=0;
  int i;
  for(i=0;i<n;i++){
    int k=s[i]-'a';
    cnt[k]++;
    if(v[k]->len%2==1 && cnt[k]==v[k]->len/2+1){
      mid=1;
      ans+=back;
    } else if(cnt[k]>v[k]->len/2){
      back++;
    } else {
      ans+=back+mid;
    }
  }
  memset(cnt,0,sizeof(int)*26);
  int *array=(int *)calloc(n/2,sizeof(int));
  int len=0;
  for(i=n-1;i>=0;i--){
    int k=s[i]-'a';
    if(cnt[k]<v[k]->len/2){
      array[len++]=v[k]->a[cnt[k]];
    }
    cnt[k]++;
  }
  int *tmp=(int *)calloc(n/2,sizeof(int));
  ans+=calcInversion(array,len,tmp);
  free(tmp);
  return ans;
}

void run(void){
  char *s=(char *)calloc(200000+1,sizeof(char));
  scanf("%s",s);
  int n=strlen(s);
  const int f=26;
  vec **v=(vec **)calloc(f,sizeof(vec *));
  int i;
  for(i=0;i<f;i++) v[i]=newVector();
  for(i=0;i<n;i++) push_back(v[s[i]-'a'],i+1);
  int odd=0;
  for(i=0;i<f;i++) if(v[i]->len%2) odd++;
  if(odd>1){
    printf("-1\n");
    return;
  }
  int64 ans=calc(s,n,v);
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:85:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^