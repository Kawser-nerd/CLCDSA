#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q) ((p)<(q)?(p):(q))
#define max(p,q) ((p)>(q)?(p):(q))
#define INF 1000000000000//10^12

struct num_t {
	int idnum;
	int a;
} ;

int compare_num(const void *a, const void *b) {
  struct num_t *A = (struct num_t *)a;
  struct num_t *B = (struct num_t *)b;
  return A->a - B->a;
}


int main(void)
{
	//?????
	int n;
	static struct num_t num[100010];;
	static int b[100010];
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	int sum=0;
	//????????
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&num[i].a);
	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	for(i=0;i<n;i++){
		b[i]=i%2;
		num[i].idnum=i%2;
	}
	
	qsort(num,n,sizeof(struct num_t),compare_num);
	
	for(i=0;i<n;i++){
		ans=ans+(num[i].idnum+b[i])%2;
	}
	
//	printf("??????\n");
	//??
	
	printf("%d",ans/2);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:41:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:44:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&num[i].a);
   ^