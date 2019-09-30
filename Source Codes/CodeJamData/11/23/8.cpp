#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <iterator>
#include <bitset>
#include <sstream>
#include <cmath>
#include <cstring>

using namespace std;

int n,m;
vector<int> nxt[2222];
int col[2222];
int ans;

void calc(int l,int r){
	if (l+1==r) return ;
	vector<int> tmp;tmp.clear();
	tmp.push_back(l);
	int cur=l;
	while (cur!=r){
		int pos=-1;
		for (int i=0;i<nxt[cur].size();i++)	{
			if (cur==l&&nxt[cur][i]==r) continue;
			if (nxt[cur][i]<=r) {
				pos=max(nxt[cur][i],pos);
			}
		}
		tmp.push_back(pos);
		cur=pos;
	}
	ans=min(ans,int(tmp.size()));
//	for (int i=0;i<tmp.size();i++) cout << tmp[i] <<"__";puts("");
	for (int i=0;i<tmp.size()-1;i++)
		calc(tmp[i],tmp[i+1]);
}

int vst[2222],cst=1;

void calc_func(int l,int r){
	if (l+1==r) return ;
	vector<int> tmp;tmp.clear();
	tmp.push_back(l);
	int cur=l;
	while (cur!=r){
		int pos=-1;
		for (int i=0;i<nxt[cur].size();i++)	{
			if (cur==l&&nxt[cur][i]==r) continue;
			if (nxt[cur][i]<=r) {
				pos=max(nxt[cur][i],pos);
			}
		}
		tmp.push_back(pos);
		cur=pos;
	}
	ans=min(ans,int(tmp.size()));
	cst++;
	vst[col[tmp[0]]]=cst;
	vst[col[tmp[tmp.size()-1]]]=cst;
	int cur_col=0,cc=2;
	for (int i=1;i<tmp.size()-1;i++){
		while ((cc<ans&&vst[cur_col]==cst)||cur_col==col[tmp[i-1]]||(i+1==tmp.size()-1&&cur_col==col[tmp[tmp.size()-1]])){
			cur_col=(cur_col+1)%ans;
		}
		col[tmp[i]]=cur_col;
		if (vst[cur_col]!=cst){
			cc++;
			vst[cur_col]=cst;
		}
	}
	
	
	for (int i=0;i<tmp.size()-1;i++)
		calc_func(tmp[i],tmp[i+1]);
}

int x[11111],y[11111];

void work(){
	cin >> n >> m;
	
	for (int i=0;i<n;i++){
		nxt[i].clear();
		if (i+1<n) nxt[i].push_back(i+1);
	}
	for (int i=0;i<m;i++) scanf("%d",&x[i]);
	
	for (int i=0;i<m;i++) scanf("%d",&y[i]);
	for (int i=0;i<m;i++){
		--x[i];--y[i];
		if (x[i]>y[i]) swap(x[i],y[i]);
		nxt[x[i]].push_back(y[i]);
	}
	ans=10000;
	calc(0,n-1);
	cout << ans <<endl;
	
	col[0]=0;col[n-1]=1;
	calc_func(0,n-1);
	for (int i=0;i<n-1;i++) 
		printf("%d ",col[i]+1);
	printf("%d\n",col[n-1]+1);
}

int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int t;cin >> t;
	for (int i=1;i<=t;i++){
		cout << "Case #"<< i << ": ";
		work();
	}
	//system("pause");
	return 0;
}
/*
2
4 1
2
4
8 3
1 1 4
3 7 7
*/
