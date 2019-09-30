#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

char AA[111];

pair<string, vector<int> > get(string A)
{
	string s; vector<int> a;
	char last = A[0]; int cnt = 1;
	for (char x : A){
		if (last != x){
			s += last;
			a.push_back(cnt);
			last = x; cnt = 1;
		}
		else cnt++;
	}
	s += last;
	a.push_back(cnt);

	return make_pair(s,a);
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int Test; scanf ("%d",&Test);
	for (int Case=1;Case<=Test;Case++){
		printf ("Case #%d: ",Case);

		int N; scanf ("%d",&N);
		scanf ("%s",AA);
		string u = get(AA).first; vector<int> v = get(AA).second;
		vector<vector<int> > p(u.size());
		for (int i=0;i<u.size();i++) p[i].push_back(v[i]);
		int cnt = 0;
		for (int i=1;i<N;i++){
			scanf ("%s",AA);
			if (u != get(AA).first){
				cnt = -1;
			}
			else{
				vector<int> v = get(AA).second;
				for (int i=0;i<u.size();i++) p[i].push_back(v[i]);
			}
		}

		if (cnt != -1){
			for (int i=0;i<p.size();i++){
				sort(p[i].begin(),p[i].end());
				for (int x:p[i]) cnt += abs(p[i][N/2]-x);
			}
		}
		if (cnt == -1) puts("Fegla Won");
		else printf ("%d\n",cnt);
	}

	return 0;
}