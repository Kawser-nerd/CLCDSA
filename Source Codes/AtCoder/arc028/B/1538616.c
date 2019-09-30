#include <stdio.h>
#define FOR(i,a,n) for(i=(a);i<(n);i++)

void push(int *heap,int *heap_size,int a){
 	int i=(*heap_size)++;
 	while(i>0){
 		int p=(i-1)/2;
 		if(heap[p]>=a) break;
 		heap[i]=heap[p];
 		i=p;
 	}
 	heap[i]=a;
 	return;
}
int pop(int *heap,int *heap_size){
 	int data=heap[0];
 	int n=heap[--(*heap_size)];
 	int pos=0;
 	while(pos*2+1<(*heap_size)){
 		int a=pos*2+1;
 		int b=pos*2+2;
 		if(b<(*heap_size)&&heap[a]<heap[b]) a=b;
 		if(n>=heap[a]) break;
 		heap[pos]=heap[a];
 		pos=a;
 	}
 	heap[pos]=n;
 	return data;
}
int heap[100000];
int heap_size=0;
int x[100000];
int id[100000];
int main(void)
{
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	FOR(i,0,n){
		scanf("%d",&x[i]);
		id[--x[i]]=i+1;
	}
	FOR(i,0,k) push(heap,&heap_size,x[i]);
	FOR(i,0,n-k+1){
		printf("%d\n",id[heap[0]]);
		push(heap,&heap_size,x[k+i]);
		pop(heap,&heap_size);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x[i]);
   ^