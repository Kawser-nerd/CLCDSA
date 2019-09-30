#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <cctype>
using namespace std;

struct CMP_STRING {
	bool operator()(const char* a, const char* b) const {
		return strcmp(a,b)<0;
	}
};

#define two(n) (1<<(n))
#define foreach(a,it) for(typeof(a.begin()) it=a.begin();it!=a.end();++it)

int TT,N,M,Q;

double questions[30][4];
vector<double> probs[2];


int main(void) {
	scanf("%d",&TT);
	for(int T=1;T<=TT;T++) {
		printf("Case #%d: ",T);
		scanf("%d %d",&M,&Q);
		for(int i=0;i<Q;i++)
			for(int j=0;j<4;j++)
				scanf("%lf",&questions[i][j]);
		probs[0].clear();
		probs[1].clear();

		for(int i=0;i<4;i++)
			probs[0].push_back(questions[0][i]);
		sort(probs[0].begin(),probs[0].end(),greater<double>());

		for(int i=1;i<Q;i++) {
			probs[i%2].clear();
			for(int j=0;j<4;j++)
				for(int k=0;k<(int)probs[(i+1)%2].size();k++) {
					probs[i%2].push_back(probs[(i+1)%2][k]*questions[i][j]);
				}
			sort(probs[i%2].begin(),probs[i%2].end(),greater<double>());
			if((int)probs[i%2].size()>M)
				probs[i%2].erase(probs[i%2].begin()+M,probs[i%2].end());

		}


		double ans=0;
		for(int i=0;i<M and i<(int)probs[(Q-1)%2].size();i++)
			ans+=probs[(Q-1)%2][i];
//		ans/=(double)probs.size();
		printf("%lf\n",ans);
	}
	return 0;
}
