#include <stdio.h>
#include <stdlib.h>
int min(int x, int y){return x<y?x:y;}

int n,A,B,C,l[8];

int search(int cur,int a,int b,int c){
//?????????,A???,B,C
	if(cur == n){//?????
		int cost = abs(a-A) + abs(b-B) + abs(c-C) - 30;
		//???????
		if(a==0 || b==0 || c==0) return 1000000000;
		else return cost;
	}
	int cost1 = search(cur+1,a,b,c);
	//????
	int cost2 = search(cur+1,a+l[cur],b,c) + 10;
	//cur????A????????
	int cost3 = search(cur+1,a,b+l[cur],c) + 10;
	int cost4 = search(cur+1,a,b,c+l[cur]) + 10;
	return min(min(cost1,cost2),min(cost3,cost4));
	
}

int main(void){
	int i;
	scanf("%d %d %d %d",&n,&A,&B,&C);
	for(i=0;i<n;i++)scanf("%d",&l[i]);
	printf("%d",search(0,0,0,0));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&n,&A,&B,&C);
  ^
./Main.c:28:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d",&l[i]);
                  ^