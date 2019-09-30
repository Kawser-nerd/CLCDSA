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
#define MAX 17
int cz[MAX];
void test(){
	R(i,MAX)cz[i] = 0;
	R(_,2){
		int pom;make(pom);pom--;
		R(i,4)R(j,4){
			int pom2;make(pom2);
			if(i==pom)cz[pom2]++;
		}
	}
	int il=0,kt;
	R(i,MAX){
		if(cz[i]==2){
			il++;
			kt=i;
		}
	}
	static int nr = 0;nr++;
	printf("Case #%d: ",nr);
	if(il == 0)printf("Volunteer cheated!\n");
	if(il == 1)printf("%d\n",kt);
	if(il > 1)printf("Bad magician!\n");
}
main(){
	int t;make(t);while(t--)test();
}
