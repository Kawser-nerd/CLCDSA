#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
 
#define mod 1000000007
#define FOR(x,to) for(int x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define long long long
inline int rei(){int x;cin>>x;return x;}
inline long rel(){long x;cin>>x;return x;}
inline string res(){string x;cin>>x;return x;}
//------------------------------------------------------- 
vector<pair<int,long>> G[131072];
vector<pair<long,long>> cost[131072];
int N;
bool OK(long X){
	for(int v=N-1;v>=0;v--){
		if(G[v].empty()){
			cost[v] = {{0,0}};
		}
		else{
			long C0 = G[v][0].second;
			long C1 = G[v][1].second;
			vector<pair<long,long>> cost0 = cost[G[v][0].first];
			vector<pair<long,long>> cost1 = cost[G[v][1].first];
			if(cost0.size() > cost1.size()){
				C0 = G[v][1].second;
				C1 = G[v][0].second;
				cost0 = cost[G[v][1].first];
				cost1 = cost[G[v][0].first];
			}
			vector<pair<long,long>> ans1;
			vector<pair<long,long>> ans2;
			for(int i=0;i<cost0.size();i++){
				int bf0 = 0;
				int bl0 = cost1.size();
				while(bf0 != bl0){
					long bc = (bf0+bl0)/2;
					if(bc == cost1.size() || C0 + C1 + cost0[i].second + cost1[bc].second <= X){
						bl0 = bc;
					}
					else{
						bf0 = bc+1;
					}
				}
				int bf1 = -1;
				int bl1 = cost1.size()-1;
				while(bf1 != bl1){
					long bc = (bf1+bl1+1)/2;
					if(bc == -1 || C0 + C1 + cost0[i].second + cost1[bc].first <= X){
						bf1 = bc;
					}
					else{
						bl1 = bc-1;
					}
				}
				bool b1 = bf0 == cost1.size();
				bool b2 = bf1 == -1;
				if(b1 && b2){
					continue;
				}
				if(b1){
					ans1.push_back({C0+cost0[i].first,C1+cost1[bf1].second});
				}
				else if(b2){
					ans1.push_back({C0+cost0[i].first,C1+cost1[bf0].first});
				}
				else{
					ans1.push_back({C0+cost0[i].first,min(C1+cost1[bf1].second,C1+cost1[bf0].first)});
				}
			}
			for(int i=cost0.size()-1;i>=0;i--){
				int bf0 = 0;
				int bl0 = cost1.size();
				while(bf0 != bl0){
					long bc = (bf0+bl0)/2;
					if(bc == cost1.size() || C0 + C1 + cost0[i].first + cost1[bc].second <= X){
						bl0 = bc;
					}
					else{
						bf0 = bc+1;
					}
				}
				int bf1 = -1;
				int bl1 = cost1.size()-1;
				while(bf1 != bl1){
					long bc = (bf1+bl1+1)/2;
					if(bc == -1 || C0 + C1 + cost0[i].first + cost1[bc].first <= X){
						bf1 = bc;
					}
					else{
						bl1 = bc-1;
					}
				}
				bool b1 = bf0 == cost1.size();
				bool b2 = bf1 == -1;
				if(b1 && b2){
					continue;
				}
				if(b1){
					ans2.push_back({C0+cost0[i].second,C1+cost1[bf1].second});
				}
				else if(b2){
					ans2.push_back({C0+cost0[i].second,C1+cost1[bf0].first});
				}
				else{
					ans2.push_back({C0+cost0[i].second,min(C1+cost1[bf1].second,C1+cost1[bf0].first)});
				}
			}
			vector<pair<long,long>> ans;
			int p1 = 0;
			int p2 = 0;
			while(p1 < ans1.size() || p2 < ans2.size()){
				if(p1 == ans1.size()){
					pair<long,long> t = ans2[p2];
					p2++;
					if(ans.size() == 0 || ans.back().second > t.second){
						ans.push_back(t);
					}
				}
				else if(p2 == ans2.size()){
					pair<long,long> t = ans1[p1];
					p1++;
					if(ans.size() == 0 || ans.back().second > t.second){
						ans.push_back(t);
					}
				}
				else{
					pair<long,long> t;
					if(ans1[p1].first < ans2[p2].first || (ans1[p1].first == ans2[p2].first && ans1[p1].second <= ans2[p2].second)){
						t = ans1[p1];
						p1++;
					}
					else{
						t = ans2[p2];
						p2++;
					}
					if(ans.size() == 0 || ans.back().second > t.second){
						ans.push_back(t);
					}
				}
			}
			cost[v] = ans;
		}
	}
	return cost[0].size();
}
void Calc(){
	N = rei();
	FOR(i,N-1){
		G[rei()-1].push_back({i+1,rei()});
	}
	long bf = 0;
	long bl = 131072*(long)131072;
	while(bf != bl){
		long bc = (bf+bl)/2;
		if(OK(bc)){
			bl = bc;
		}
		else{
			bf = bc+1;
		}
	}
	cout << bf << endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(false), cin.tie(0);
	cout.tie(0); Calc(); return 0;
}