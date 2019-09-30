#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

#define debug(x) cerr<<#x<<"="<<(x)<<endl;

char worm[401][401];
int dist[401][401];
int most[401][401];
int adj[401];
int adj2[401][401];
int goodcount[401];
int goodlist[401][401];
#define aclear(arr) memset(arr, 0, sizeof(arr))

void eval(){
	aclear(worm);
	aclear(dist);
	aclear(most);
	aclear(adj);
	aclear(adj2);
	aclear(goodcount);
	int P, W;
	scanf("%d %d", &P, &W);
	for(int i=0; i<W; i++){
		int x, y;
		scanf("%d,%d", &x, &y);
		worm[x][y]=worm[y][x]=dist[y][x]=dist[x][y]=1;
		adj[x]++;
		adj[y]++;
	}
	for(int k=0; k<P; k++)
	for(int i=0; i<P; i++)
	for(int j=0; j<P; j++){
		if(i!=j && j!=k && k!=i && worm[i][k] && worm[j][k])
			adj2[i][j]++;
		if(!dist[i][k] || !dist[k][j] || i==j)
			continue;
		int nd=dist[i][k]+dist[k][j];
		if(dist[i][j]==0 || dist[i][j]>nd)
			dist[i][j]=nd;
	}
	int ans1=dist[0][1]-1;
	char good[400]={0};
	for(int i=0; i<P; i++)
		if(dist[0][i]!=0 && dist[i][1]!=0 && dist[0][i]+dist[i][1]==dist[0][1]){
			good[i]=1;
			goodlist[dist[0][i]][goodcount[dist[0][i]]++]=i;
		}
	queue<pair<int, int> > q;
	q.push(make_pair(400, 0));
	most[400][0]=adj[0];
	int ans2=adj[0];
	for(; !q.empty(); q.pop()){
		int cur=q.front().second;
		int prev=q.front().first;
		for(int next=0; next<P; next++){
			if(!worm[cur][next])
				continue;
			if(!good[next])
				continue;
			if(dist[next][1]>=dist[cur][1])
				continue;
			int add=adj[next]-adj2[next][cur]-adj2[next][prev]-1-(prev==400);
			int d=dist[0][cur];
			for(int i=0; i<goodcount[d]; i++){
				int p=goodlist[d][i];
				if(worm[p][prev] && worm[p][cur] && worm[p][next] && p!=cur)
					add++;
			}
			add+=most[prev][cur];
			if(most[cur][next]==0){
				q.push(make_pair(cur, next));
			}
			most[cur][next]=max(most[cur][next], add);
			if(dist[next][1]==1)
				ans2=max(ans2, add);
		}
	}
	printf("%d %d\n", ans1, ans2);
}

int main(){
	int cases;
	string line;
	getline(cin, line);
	istringstream(line)>>cases;
	for(int i=1; i<=cases; i++){
		cout<<"Case #"<<i<<": ";
		eval();
	}
	return 0;
}
