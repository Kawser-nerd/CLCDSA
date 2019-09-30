#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b){
	int *c=(void*)a;
	int *d=(void*)b;
	return(*c-*d);
}
int compare1(const void *a,const void *b){
	int *c=(void*)a;
	int *d=(void*)b;
	return(*d-*c);
}

int main(){
	int num,n,m,i,j,record[2][1000];
	long long sum;
	scanf("%d",&num);
	n=0;
	while(n<num){
		scanf("%d",&m);
		for(i=0;i<m;i++)
			scanf("%d",&record[0][i]);
		for(i=0;i<m;i++)
			scanf("%d",&record[1][i]);
		qsort(record[0],m,sizeof(record[0][0]),compare);
		qsort(record[1],m,sizeof(record[1][0]),compare1);
		sum=0;
		for(i=0;i<m;i++)
			sum+=(record[0][i]*record[1][i]);
		printf("Case #%d: %lld\n",n+1,sum);
		n++;
	}
	return 0;
}
