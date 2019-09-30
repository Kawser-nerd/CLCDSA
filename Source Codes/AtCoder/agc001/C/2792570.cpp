#include <stdio.h>
#include <vector>

using namespace std;

int n,k;
int _ans,ans=0;
int l_max;

vector<int> edge[2000];
bool arrived[2000];

void calc(int now, int len) {
	if(arrived[now]) return;
	arrived[now] = true;
	_ans++;
	if(len<l_max) for(int next : edge[now]) calc(next,len+1);
}

int main() {
	scanf("%d%d",&n,&k);
	l_max = (k+1)/2;
	for(int i = 0; i < n-1; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	if(k%2==0) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) arrived[j] = false;
			_ans = 0;
			calc(i,0);
			ans = max(ans,_ans);
		}
		printf("%d\n",n-ans);
	}else {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < edge[i].size(); j++) {
				for(int l = 0; l < n; l++) arrived[l] = false;
				_ans = 0;
				arrived[edge[i][j]] = true;
				calc(i,1);
				arrived[edge[i][j]] = false;
				calc(edge[i][j],1);
				//printf("%d,%d,%d\n",i,edge[i][j],_ans);
				ans = max(ans,_ans);
			}
		}
		printf("%d\n",n-ans);
	}
}