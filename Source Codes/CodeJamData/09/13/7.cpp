#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <complex> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <cassert> 
using namespace std;

double C[41][41];
double ans[41],prob[41];
int main(){
	int T,tests=0;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		assert(n>=m);
		for(int i=0;i<=n;i++){
			C[i][i]=C[i][0]=1;
			for(int j=1;j<i;j++)
				C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
		ans[n]=0;
		for(int i=n-1;i>=0;i--){
			memset(prob,0,sizeof(prob));
			for(int j=0;j<=m;j++)if(j<=i&&m-j<=n-i)
				prob[i-j+m]=C[i][j]*C[n-i][m-j]/C[n][m];
			ans[i]=0;
			for(int j=i+1;j<=n;j++)
				ans[i]+=prob[j]/(1-prob[i])*ans[j];
			ans[i]+=1/(1-prob[i]);
		}
		printf("Case #%d: %.10lf\n",++tests,ans[0]);
	}
}
