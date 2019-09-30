#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void){
	long long N, M;
	cin >> N >> M;
	vector<pair<long long , long long>> store(N);

	for(int i = 0; i < N; i++){
		cin >> store[i].first >> store[i].second;
	}
	sort(store.begin(), store.end());
	long long need = 0;
	for(int i = 0; i < N; i++){
		if(store[i].second >= M){
			need += M*store[i].first;
			break;
		}else{
			need += store[i].second * store[i].first;
			M -= store[i].second;
		}
	}
	cout << need <<endl;
	return 0;
}