#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#define MAX 1001001
int t[MAX],n,p,q,r,s;
void test(){
	make(n);
	scanf("%d%d%d%d",&p,&q,&r,&s);
	LL all = 0;
	R(i,n){
		t[i] = (((LL)i*p + q) % r + s);
		all += t[i];
	//	printf("%d ",t[i]);
	}
	//puts("");
	int j=0;
	LL sum = 0,sum2 = 0,wyn = all;
	R(i,n){
		while(j<i && max(sum,sum2) >= max(sum+t[j],sum2-t[j])){
			sum += t[j];
			sum2 -= t[j];
			j++;
		}
		LL pom = max(max(sum,sum2),all - sum - sum2);
		if(pom < wyn)wyn = pom;
		sum2 += t[i];
	}
	static int test_nr = 0;test_nr++;
	printf("Case #%d: ",test_nr);
	//printf("%lld %lld\n",all-wyn,wyn*2);
	printf("%.10lf\n",(double)(all - wyn) / all);
}
main(){
	int _;make(_);while(_--)test();
}
