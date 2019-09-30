#include <stdio.h>
#include <stdlib.h>

int search(long long *array,long long key,int low,int high){
	if(low<high){
		int mid = low+(high-low)/2;
		if(key<=array[mid])return search(array,key,low,mid);
		if(key>array[mid])return search(array,key,mid+1,high);
	}
	if(key>array[low])return low+1;
	return low;
}

int main(void){
	int N,M,i,ans=0,t,c=0,d=0;
	long long X,Y,a[100001],b[100001],time=0;
	scanf("%d%d%lld%lld",&N,&M,&X,&Y);
	for(i=0;i<N;i++)scanf("%lld",&a[i]);
	for(i=0;i<M;i++)scanf("%lld",&b[i]);
	int now = 0;//0:a, 1:b
	while(1){
		if(!now){//A->B
			t=time>a[N-1]?-1:search(a,time,c,N-1);
			if(t<0)break;
			time=a[t]+X;now=1;c=t;
		}else{
			t=time>b[M-1]?-1:search(b,time,d,M-1);
			if(t<0)break;
			ans++;time=b[t]+Y;now=0;d=t;
		}
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%lld%lld",&N,&M,&X,&Y);
  ^
./Main.c:18:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<N;i++)scanf("%lld",&a[i]);
                  ^
./Main.c:19:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<M;i++)scanf("%lld",&b[i]);
                  ^