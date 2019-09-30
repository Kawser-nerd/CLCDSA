#include <stdio.h>
#define FOR(i,a,n) for(i=a;i<n;i++)
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ll long long

int heap[100001];
int num=0;
void push(int a){
 	int i=num++;
 	while(i>0){
 		int p=(i-1)/2;
 		if(heap[p]<=a) break;
 		heap[i]=heap[p];
 		i=p;
 	}
 	heap[i]=a;
 	return;
}
int pop(void){
 	int data=heap[0];
 	int n=heap[--num];
 	int pos=0;
 	while(pos*2+1<num){
 		int a=pos*2+1;
 		int b=pos*2+2;
 		if(b<num&&heap[a]>heap[b]) a=b;
 		if(n<=heap[a]) break;
 		heap[pos]=heap[a];
 		pos=a;
 	}
 	heap[pos]=n;
 	return data;
}
int a[300000];
ll k[100001];
int main(void)
{
     int n,p,size,i;
     ll sum=0,res;
     scanf("%d",&n);
     size=3*n;
     FOR(i,0,size) scanf("%d",&a[i]);
     FOR(i,0,n){
     	sum+=a[i];
     	push(a[i]);
     }
     k[0]=sum;
     FOR(i,1,n+1){
     	push(a[i+n-1]);
     	p=pop();
     	sum+=(a[i+n-1]-p);
     	k[i]=sum;
     }
     sum=num=0;
     FOR(i,0,n){
     	sum+=a[size-i-1];
     	push(-a[size-i-1]);
     }
     res=k[n]-sum;
     FOR(i,1,n+1){
     	push(-a[2*n-i]);
     	p=-pop();
     	sum+=(a[2*n-i]-p);
     	res=MAX(res,k[n-i]-sum);
     }
     printf("%lld\n",res);
 	return 0;
} ./Main.c: In function ‘main’:
./Main.c:40:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d",&n);
      ^
./Main.c:42:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      FOR(i,0,size) scanf("%d",&a[i]);
                    ^