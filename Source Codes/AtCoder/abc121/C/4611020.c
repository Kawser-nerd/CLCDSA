#include<stdio.h>
#include<stdlib.h>
typedef unsigned long long int lli;
typedef struct DATA{
	lli price;
	int bottle;
} DATA;
int asc(const void *a,const void*b){
	DATA *data_a = (DATA*)a;
	DATA *data_b = (DATA*)b;
	if(data_a->price > data_b->price){
		return 1;
	}
	return -1;
}
int main(void){
	int N,M;
	DATA data[100000];
	scanf("%d %d",&N,&M);
	for(int i = 0;i<N;i++){
		scanf("%llu %d",&data[i].price,&data[i].bottle);
	}
	
	qsort(data,N,sizeof(DATA),asc);
	int count =0;
	lli price = 0;
	for(int i=0;i<N;i++){
		if(count + data[i].bottle > M){
			price += (M-count)*data[i].price;
			break;
		}else{
			price += data[i].price * data[i].bottle;
			count += data[i].bottle;
		}
	}
	printf("%llu\n",price);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu %d",&data[i].price,&data[i].bottle);
   ^