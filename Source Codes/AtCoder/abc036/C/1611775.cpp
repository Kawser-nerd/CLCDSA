#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PI 4*atan(1.0)
typedef long long ll;
typedef long double ld;
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
const int SIZE=100050;
//int arr[SIZE]={};
//????????
//??????vector?????????vector???
vector<int> comp(vector<int> v){
	map<int,int> pam;
	int sz=v.size();
	for(int i=0;i<sz;i++){
		pam[v[i]]=0;
	}
	//????1????????nc=1???
	int nc=0;
	for(pair<int,int> i:pam){
		pam[i.first]=nc;
		nc++;
	}
	vector<int> w;
	for(int i=0;i<sz;i++){
		w.push_back(pam[v[i]]);
	}
	return w;
}
//?????
int main(){
	int N;
	cin>>N;
	vector<int> v;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	vector<int> w=comp(v);
	for(int i:w){
		cout<<i<<endl;
	}
	return 0;
}