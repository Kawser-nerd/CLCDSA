#include <stdio.h>
#include <stdlib.h>

typedef struct box{
	int has;
	int pos;
	int num;
}box;

int main(){
	int i;
	int n,m;
	int *x,*y;
	box *b;
	int res = 0;

	scanf("%d %d",&n,&m);

	x = calloc(sizeof(int),m);
	y = calloc(sizeof(int),m);
	b = calloc(sizeof(box),n);
	for(i = 0;i < m;i++){
		scanf("%d %d",&x[i],&y[i]);
		x[i]--;
		y[i]--;
	}
	b[0].has = 1;
	for(i = 0;i < n;i++){
		b[i].num = 1;
	}
	for(i = 0;i < m;i++){
		b[x[i]].num -= 1;
		b[y[i]].num += 1;
		if(b[x[i]].has){
			b[y[i]].has = 1;
		}
		if(b[x[i]].num == 0){
			b[x[i]].has = 0;
		}
	}
	for(i = 0;i < n;i++){
		res += b[i].has;
	}
	printf("%d\n", res);



	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&x[i],&y[i]);
   ^