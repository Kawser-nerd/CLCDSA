#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct kazu_t {
	int idnum;
	int p;
} ;

int compare_kazu(const void *a, const void *b) {
  struct kazu_t *A = (struct kazu_t *)a;
  struct kazu_t *B = (struct kazu_t *)b;
  return A->p - B->p;
}

int main(void)
{
	//?????
	int n;
	int i,j;
	int flag=0;
	int ans=0;
	int count=0;
	static struct kazu_t kazu[200010];
	//????????
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&kazu[i].p);
		kazu[i].idnum=i;
	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	qsort(kazu, n, sizeof(struct kazu_t), compare_kazu);
	
	count=1;
	for(i=1;i<n;i++){
		if(kazu[i-1].idnum<kazu[i].idnum){
			count++;
		}else{
			if(ans<count){
				ans=count;
			}
			count=1;
		}
	}
	if(ans<count) ans=count;
	
//	printf("??????\n");
	//??
	
	printf("%d",n-ans);
	
//	printf("???????\n");
	
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&kazu[i].p);
   ^