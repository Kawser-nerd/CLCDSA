#include <stdio.h>
long m,n;
long a[500000];
long b[500000];
int main(){
	scanf("%li %li",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%li %li",&a[i],&b[i]);
	sort(1,m);
	long x=n+1;
	long ans=0;
	for (int i=m;i>=1;i--)
		if (b[i]<x){
			ans++;
			x=a[i]+1;
		}		
	printf("%li",ans);
}
int sort(long x,long y){
	long l=x;
	long r=y;
	long m=a[(l+r)/2];
	long bm=b[(l+r)/2];
	while (l<r){
		while (a[l]<m||((a[l]==m)&&(b[l]<bm))) l++;
		while (a[r]>m||((a[r]==m)&&(b[r]>bm))) r--;
		if (l<=r){
			long z=a[l];
			a[l]=a[r];
			a[r]=z;
			z=b[l];
			b[l]=b[r];
			b[r]=z;
			l++;
			r--;
		}

	}
	if (l<y) sort(l,y);
	if (x<r) sort(x,r);
	return(0);
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: implicit declaration of function ‘sort’ [-Wimplicit-function-declaration]
  sort(1,m);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%li %li",&n,&m);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%li %li",&a[i],&b[i]);
   ^