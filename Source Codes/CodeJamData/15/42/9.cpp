#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
void work1(int Cas){
	db R,C,R1,C1;
	scanf("%lf%lf%lf%lf",&R,&C,&R1,&C1);
	if(C1!=C){
		printf("Case #%d: IMPOSSIBLE\n",Cas);
		return;
	}
	printf("Case #%d: %.8lf\n",Cas,R/R1);
}
void work2(int Cas){
	db A,B,C,V;
	db L1,L2;
	scanf("%lf%lf",&V,&C);
	scanf("%lf%lf",&L1,&A);
	scanf("%lf%lf",&L2,&B);

	
	if(A==B){
		if(A!=C){
			printf("Case #%d: IMPOSSIBLE\n",Cas);
			return;
		}
		printf("Case #%d: %.8lf\n",Cas,V/(L1+L2));
		return;
	}
	
	db V2=(C-A)*V/(B-A);
	db V1=V-V2;
	if(V1<0||V2<0){
		printf("Case #%d: IMPOSSIBLE\n",Cas);
		return;
	}
	printf("Case #%d: %.8lf\n",Cas,max(V1/L1,V2/L2));
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d",&T);
	rep(Cas,1,T){
		int n;scanf("%d",&n);
		if(n==1)work1(Cas);
		else if(n==2)work2(Cas);
	}
	return 0;
}









