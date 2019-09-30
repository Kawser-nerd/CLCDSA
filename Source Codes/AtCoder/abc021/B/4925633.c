#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
  return *(int*)a - *(int*)b;
}

int main(void){
  int n,k,a,b,i;
  scanf("%d",&n);
  scanf("%d %d",&a,&b);
  scanf("%d",&k);
  int p[k];
  for(i=0;i<k;i++) scanf("%d",&p[i]);
  qsort(p,k,sizeof(int),cmp);
  if(p[k-1]==a || p[k-1]==b){
    printf("NO\n");
    return 0;
  }
  for(i=0;i<k-1;i++){
    if(p[i]==p[i+1] || a==p[i] || b==p[i]){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^
./Main.c:14:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<k;i++) scanf("%d",&p[i]);
                    ^