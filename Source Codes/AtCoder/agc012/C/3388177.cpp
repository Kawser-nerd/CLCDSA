#include <cstdio>

const int N=202;
int a[N],mx=-1,t;
long long n;

int main(){
	scanf("%lld",&n);
	for(int i=40;~i;--i)
		if((n>>i)&1)
			if(~mx)a[i]=mx+(++t);
			else mx=i;
	printf("%d\n",mx+mx+2+t+t);
	if(a[0])printf("%d ",a[0]);
	for(int i=1;i<=mx;++i){
		printf("%d ",i);
		if(a[i])printf("%d ",a[i]);
	}
	for(int i=1;i<=mx+t;++i)printf("%d ",i);
	printf("%d %d\n",mx+t+1,mx+t+1);
} ./Main.cpp:12:4: warning: add explicit braces to avoid dangling else [-Wdangling-else]
                        else mx=i;
                        ^
1 warning generated.