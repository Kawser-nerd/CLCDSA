#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int index,h;
} data;

int compare(const void *x, const void *y){
	return ((data*)x)->h - ((data*)y)->h;
}

data people[100000];
int ans[100000];

int main(void){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&people[i].h);
		people[i].index = i;
	}
	qsort(people,n,sizeof(data),compare);
	int num=0;
	for(i=0;i<n;i++){
		if(i>0 && people[i].h != people[i-1].h)num++;
		ans[people[i].index]=num;
	}
	for(i=0;i<n;i++)printf("%d\n",ans[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&people[i].h);
   ^