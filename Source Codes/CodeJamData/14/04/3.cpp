#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
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
#define MAX 1001
int n;
D a[MAX],b[MAX];
void test(){
	make(n);
	R(i,n)scanf("%lf",&a[i]);
	R(i,n)scanf("%lf",&b[i]);
	sort(a,a+n);
	sort(b,b+n);
	int wyn1 = 0;
	R(i,n){
		bool x = 1;
		R(j,i+1)if(a[n-i-1+j] < b[j])x=0;
		if(x)wyn1 = i+1;
	}
	int j = 0;
	R(i,n)if(b[i] > a[j])j++;
	int wyn2 = n - j;
	static int nr = 0;nr++;
	printf("Case #%d: %d %d\n",nr,wyn1,wyn2);
}
main(){
	
	int t;make(t);while(t--)test();
}
