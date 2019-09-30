//
#include <iomanip>
#include <utility>
#include <algorithm>
#include <type_traits>
#include <set>
#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <memory>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <vector>
#include <array>
#include <chrono>
#include <random>
#include <forward_list>
#include <iomanip>
#include <functional>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <numeric>


using namespace std;

#define debug(n) cout << n << endl;
#define REP(i,m,n) for(int i=m;i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define ALL(x) (x).begin(),(x).end()
#define omajinai ios::sync_with_stdio(false); cin.tie(0)


int main(){
	int n,t;
	scanf("%d %d\n", &n, &t);
	vector<int> a(n);
	rep(i,n){
		scanf("%d\t", &a[i]);
	}
	int counter = 0;
	int min_v = a[0];
	int max_score = 0;
	REP(i,1,n){
		if(min_v + max_score < a[i]){
			max_score = a[i] - min_v;
			counter = 1;
			// updates max value;
		}
		else if(min_v + max_score == a[i]){
			counter++;
		}
		else{
			min_v = std::min(min_v, a[i]);
		}
	}
	printf("%d\n", counter);
	return 0;
}