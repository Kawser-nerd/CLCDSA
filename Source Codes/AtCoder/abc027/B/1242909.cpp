#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
	int N, all=0;
	cin >> N;

	vector<int> v(N);
	for(int i=0; i<N; i++) cin >> v[i];
	for(int i=0; i<N; i++) all += v[i];
	
	if(all%N != 0) {
		cout << -1 << endl;
		return 0;
	}

	int h = all/N, tmp=0, res=0;
	for(int i=0, cnt=1; i<N-1; i++,cnt++){
		tmp += v[i];
		if(tmp != h*cnt) res++;
	}

	cout << res << endl;
}