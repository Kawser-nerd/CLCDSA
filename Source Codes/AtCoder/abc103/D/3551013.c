#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct kenka_t {
	int a;
	int b;
} ;

int compare_kenka(const void *c, const void *d) {
  struct kenka_t *A = (struct kenka_t *)c;
  struct kenka_t *B = (struct kenka_t *)d;
  return A->a - B->a;
}


int main(void)
{
	//?????
	int n,m;
	int i,j,k;
	int flag;
	int ans,temp;
	static int anew[100010];
	static int bnew[100010];
	struct kenka_t kenka[100010];
	
	//????????
	scanf("%d %d",&n,&m);
	
	for(i=0;i<m;i++){
		scanf("%d %d",&kenka[i].a,&kenka[i].b);
	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	qsort(kenka, m, sizeof(struct kenka_t), compare_kenka);
	
	k=0;
	for(i=0;i<m-1;i++){
//		printf("%d?????????????\n",i);
		j=i+1;
		flag=1;
		while(kenka[j].a<kenka[i].b){
			if(kenka[j].b<kenka[i].b){
				flag=0;
				break;
			}
			j++;
		}
//		printf("while???\n");
		if(flag==1){
			anew[k]=kenka[i].a;
			bnew[k]=kenka[i].b;
			k++;
//			printf("%d %d???\n",kenka[i].a,kenka[i].b);
		}else{
//			printf("%d %d??????\n",kenka[i].a,kenka[i].b);
		}
	}
	anew[k]=kenka[m-1].a;
	bnew[k]=kenka[m-1].b;
	k++;
	
//	printf("\n");
//	for(i=0;i<k;i++){
//		printf("%d %d\n",anew[i],bnew[i]);
//	}
	
	ans=0;
	for(i=0;i<k;i++){
		if(i==0){
			ans++;
			temp=bnew[i];
//			printf("%d??????\n",temp);
		}else if(anew[i]>=temp){
			ans++;
			temp=bnew[i];
//			printf("%d??????\n",temp);
		}
	}
	
	
	
	
//	printf("??????\n");
	
	//??
	printf("%d",ans);
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&kenka[i].a,&kenka[i].b);
   ^