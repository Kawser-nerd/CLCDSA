#include <stdio.h>
#include <stdlib.h>

#define N 2001

typedef struct vertex{
	short int next[N];
	short int length;
} vertex;

vertex field[N];


int count(int i,int k,int r);

int main(){
	int n,k;
	int i,j;
	int a,b;
	int r;
	scanf("%d %d",&n,&k);
	for(i = 0;i < n-1;i++){
		scanf("%d %d",&a,&b);
		field[a].next[field[a].length++] = b;
		field[b].next[field[b].length++] = a;
	}

	r = k / 2;
	b = 0;
	if(k%2){
		for(i = 1;i <= n;i++){
			for(j = 0;j < field[i].length;j++){
				a = count(i,field[i].next[j],r) + count(field[i].next[j],i,r);
				if(b < a){
					b = a;
				}
			}
		}
	}else{
		for(i = 1;i <= n;i++){
			a = count(i,0,r);
			if(b < a){
				b = a;
			}
		}		
	}

	printf("%d\n", n - b);
	return 0;
}
int count(int i,int pre,int r){
	int res = 1;
	int j;
	if(r == 0){
		return res;
	}
	for(j = 0;j < field[i].length;j++){
		if(field[i].next[j] == pre){
			continue;
		}
		res += count(field[i].next[j],i,r-1);
	}
	return res;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&k);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^