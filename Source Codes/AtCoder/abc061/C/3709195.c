#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define llong long long
#define fr(i,l,r) for(i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))

struct insert_t {
	int num;
	llong int kosu;
} ;

int compare_insert(const void *a, const void *b) {
  struct insert_t *A = (struct insert_t *)a;
  struct insert_t *B = (struct insert_t *)b;
  return A->num - B->num;
}



int main(void)
{
	//?????
	int n;
	long int k;
	static struct insert_t insert[100010];
	
	//??????
	int i,j,l;
	int flag=0;
	int ans=0;
	llong int count=0;
	int temp,temp1,temp2;
	int max,min;
	int len;
	//????????
	
	scanf("%d %ld",&n,&k);
	
	for(i=0;i<n;i++){
		scanf("%d %lld",&insert[i].num,&insert[i].kosu);
	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	qsort(insert, n, sizeof(struct insert_t), compare_insert);
	
	for(i=0;i<n;i++){
		count=count+insert[i].kosu;
		if(count-k>=0){
			printf("%d",insert[i].num);
			return 0;
		}
	}
	
//	printf("??????\n");
	//??
	
	printf("error");
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:41:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %ld",&n,&k);
  ^
./Main.c:44:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %lld",&insert[i].num,&insert[i].kosu);
   ^