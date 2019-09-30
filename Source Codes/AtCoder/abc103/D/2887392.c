#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int r;
  int l;
} des_t;

int cmp(const void *p1, const void *p2){
  return((des_t*)p1)->r - ((des_t*)p2)->r;
}

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  des_t des[m];
  int i;
  for(i=0;i<m;i++) scanf("%d %d", &des[i].r, &des[i].l);
  qsort(des, m, sizeof(des_t), cmp);
  int j,s=1,tmp1,tmp2,flag=0;
  des_t des2[m];
  des2[0].r = des[0].r;
  
  des2[0].l = des[0].l;
  for(i=1;i<m;i++){
    tmp1 = des[i].r;
    tmp2 = des[i].l;
    for(j=0;j<s;j++){
      if(des2[j].l<=tmp1 || des2[j].r>=tmp2){
	continue;
      }
      else if(des2[j].r<=tmp1||des2[j].l>=tmp2){
	flag = 1;
	if(des2[j].r<tmp1) des2[j].r = tmp1;
	if(des2[j].l>tmp2) des2[j].l = tmp2;
	break;
      }
      else if(des2[j].r>=tmp1 && des2[j].l<=tmp2){
	flag = 1;
	break;
      }
      else printf("error\n");
    }
    if(flag==0){
      des2[s].r = tmp1;
      des2[s].l = tmp2;
      s++;
    }
    //printf(" %d %d %d\n",s, des2[s-1].r, des2[s-1].l);
    flag = 0;
  }
  printf("%d\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &m);
   ^
./Main.c:18:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<m;i++) scanf("%d %d", &des[i].r, &des[i].l);
                    ^