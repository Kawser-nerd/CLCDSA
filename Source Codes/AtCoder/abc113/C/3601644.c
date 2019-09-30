#include <stdio.h>
#include <stdlib.h>
#define ll long long int

typedef struct{
	int p;
	ll y;
	int idx;
	int id;
}data;

int compare(const void *a, const void *b){
	return (((data*)a)->y - ((data*)b)->y);
}

int comp2(const void *a, const void *b){
	return (((data*)a)->idx - ((data*)b)->idx);
}

int main(void){
	int n,m,i,tmp[100001]={0};
	scanf("%d %d",&n,&m);
	data city[m];
	for(i=0;i<m;i++){
		scanf("%d %lld",&city[i].p,&city[i].y);
		city[i].idx=i;
	}
	qsort(city, m, sizeof(data), compare);
	for(i=0;i<m;i++){
		++tmp[city[i].p-1];
		city[i].id=tmp[city[i].p-1];
	}
	qsort(city,m,sizeof(data),comp2);
	for(i=0;i<m;i++){
		printf("%06d%06d\n",city[i].p,city[i].id);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %lld",&city[i].p,&city[i].y);
   ^