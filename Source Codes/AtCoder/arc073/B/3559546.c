#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct item_t {
	int w;
	int v;
} ;

int compare_item(const void *a, const void *b) {
  struct item_t *A = (struct item_t *)a;
  struct item_t *B = (struct item_t *)b;
  return A->w - B->w;
}

int compare_int(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}


int main(void)
{
	//?????
	int n;
	long int weight;
	int i,j,k,l;
	struct item_t item[110];
	long int kati[4][110];
	long int katilen[4]={0,0,0,0};
	long int katisum[4][110];
	long int temp;
	long int w1;
	long int ans;
	
	//????????
	scanf("%d %ld",&n,&weight);
	
	for(i=0;i<n;i++){
		scanf("%d %d",&item[i].w,&item[i].v);
	}
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	w1=item[0].w;
	qsort(item, n, sizeof(struct item_t), compare_item);
	
//	printf("qsort?????\n");
	for(i=0;i<n;i++){
//		printf("w=%d,v=%d\n",item[i].w,item[i].v);
	}
	
	j=0;
	k=0;
	for(i=0;i<n;i++){
		if(i==0){
			//??????
		}else if(item[i].w!=item[i-1].w){
			katilen[j]=k+1;
			j++;
			k=0;
		}else{
			k++;
		}
		kati[j][k]=item[i].v;
	}
	katilen[j]=k+1;
	
	
	for(i=0;i<4;i++){
		qsort(kati[i], katilen[i], sizeof(long int), compare_int);
		for(j=0;j<katilen[i];j++){
			if(j==0){
				katisum[i][j]=kati[i][j];
			}else{
				katisum[i][j]=katisum[i][j-1]+kati[i][j];
			}
		}
	}
	
	for(i=0;i<4;i++){
//		printf("w=%d??????\n{",w1+i);
		for(j=0;j<katilen[i];j++){
			if(j==0){
//				printf("%d",katisum[i][j]);
			}else{
//				printf(",%d",katisum[i][j]);
			}
		}
//		printf("}\n");
	}
	
	ans=0;
	for(i=0;i<katilen[0]+1;i++){
		for(j=0;j<katilen[1]+1;j++){
			for(k=0;k<katilen[2]+1;k++){
//				printf("i=%d,j=%d,k=%d,wsum=%d\n",i,j,k,w1*i+(w1+1)*j+(w1+2)*k);
				
				if(weight-w1*i-(w1+1)*j-(w1+2)*k>=0){
					l=(weight-w1*i-(w1+1)*j-(w1+2)*k)/(w1+3);
					if(l>katilen[3]) l=katilen[3];
					temp=0;
					if(i!=0) temp=temp+katisum[0][i-1];
					if(j!=0) temp=temp+katisum[1][j-1];
					if(k!=0) temp=temp+katisum[2][k-1];
					if(l!=0) temp=temp+katisum[3][l-1];
					
//					printf("i=%d,j=%d,k=%d,l=%d,temp=%d\n\n",i,j,k,l,temp);
					if(ans<temp) ans=temp;
				}
			}
		}
	}
	
	
	
//	printf("??????\n");
	
	//??
	
	
	printf("%ld",ans);
	
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %ld",&n,&weight);
  ^
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&item[i].w,&item[i].v);
   ^