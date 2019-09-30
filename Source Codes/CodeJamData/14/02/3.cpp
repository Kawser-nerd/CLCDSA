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
D c,f,x,wyn;
void test(){
	scanf("%lf%lf%lf",&c,&f,&x);
	wyn = x/2;
	D czas = 0;
	int i;
	for(i=0;1;i++){
		czas += c/(2+i*f);
		D pom = czas + x/(2+(i+1)*f);
		if(pom < wyn){
			wyn = pom;
		}else
			break;
	}
	static int nr = 0;nr++;
	printf("Case #%d: %.8f\n",nr,wyn);
	//printf("%lf %lf %lf %d\n",c,f,x,i);
}
main(){
	int t;make(t);while(t--)test();
}
