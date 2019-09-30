#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int a[101];
int cnt[101]={};
bool f(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i];
	}
	sort(a,a+N);
	int m=a[N-1];
	if(m==1){
		if(N==2){
			return true;
		}
		else{
			return false;
		}
	}
	int l=(m+1)/2;
	for(int i=0;i<N;i++){
		if(a[i]<l){
			return false;
		}
		cnt[a[i]]++;
	}
	if(m%2==0){
		cerr << a[l] << endl;
		if(cnt[l]!=1){
			return false;
		}
		for(int i=l+1;i<=m;i++){
			if(cnt[i]<2){
				return false;
			}
		}
	}
	else{
		if(cnt[l]!=2){
			return false;
		}
		for(int i=l+1;i<=m;i++){
			if(cnt[i]<2){
				return false;
			}
		}
	}
	return true;
}

int main() {

	if(f()){
		cout << "Possible" << endl;
	}
	else{
		cout << "Impossible" << endl;
	}


	return 0;
}