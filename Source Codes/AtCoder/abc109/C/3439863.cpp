#include<cstdio>
int abs(int x) {
	return (x>0)?x:-x;
}
int n,k;
int gcd(int a,int b) {
	return (b==0)?a:gcd(b,a%b);
}
int main()
{
	int x,G;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d",&x);
		if(i==1) G=abs(x-k);
		else G=gcd(G,abs(x-k));
	}
	printf("%d",G);
}