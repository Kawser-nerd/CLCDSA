#include <stdio.h>
#include <stdlib.h>
typedef struct dat{
	int num,p,y;
}Data;
int cmp(const void *a, const void *b) {
  return ((Data *)a)->y-((Data *)b)->y;
}
int main(){
  int n,m,i;
  scanf("%d%d",&n,&m);
  Data c[m];
  int pr[m],id[m],pc[1000001];
  for(i=0;i<m;i++){
    scanf("%d%d",&c[i].p,&c[i].y);
	c[i].num=i;
	pr[i]=c[i].p;
  }
  qsort(c,m,sizeof(Data),cmp);
  for(i=0;i<m;i++) id[c[i].num]=++pc[c[i].p];
  for(i=0;i<m;i++) printf("%06d%06d\n",pr[i],id[i]);
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&c[i].p,&c[i].y);
     ^