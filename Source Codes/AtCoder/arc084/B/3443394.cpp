#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#define ll long long
using std::pair;
using std::make_pair;
using std::queue;
int k;
const int N = 1e5+1e3;
int dis[N];
int main(){
	scanf("%d",&k);
	std::deque<pair<int,int> > q;
	q.push_back(make_pair(1,1));
	while(!q.empty()){
		pair<int,int> now=q.front();q.pop_front();
		if(dis[now.first])
			continue;	
		dis[now.first]=1;
		if(now.first==0){
			printf("%d",now.second);
			return 0;
		}
		q.push_front((make_pair((now.first*10)%k,now.second)));
		q.push_back((make_pair((now.first+1)%k,now.second+1)));		
	}
	return 0;
}