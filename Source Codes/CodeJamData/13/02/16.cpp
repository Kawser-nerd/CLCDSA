#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool canCut(int x, int y, const vector< vector < int > > &ds){
	bool ok = true;
	for (int y2 = 0; y2 < ds[x].size(); y2++){
		if (ds[x][y2] > ds[x][y]){
			ok = false;
			break;
		}
	}
	if (ok){
		return true;
	}
	ok = true;
	for (int x2 = 0; x2 < ds.size(); x2++){
		if (ds[x2][y] > ds[x][y]){
			ok = false;
			break;
		}
	}
	if (ok){
		return true;
	}
	return false;

}

string solve(const vector< vector < int > > &ds){
	for (int i = 0; i < ds.size(); i++){
		for (int j = 0; j < ds[i].size(); j++){
			if (!canCut(i, j, ds)){
				return "NO";
			}
		}
	}
	return "YES";
}

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		int N, M;
		cin >> N >> M;
		vector < vector < int > > desiredSize;
		for (int j = 0; j < N; j++){
			desiredSize.push_back(vector<int>());
			for (int k = 0; k < M; k++){
				int data;
				cin >> data;
				desiredSize[desiredSize.size()-1].push_back(data);
			}
		}
		cout << "Case #" << (i + 1) << ": " << solve(desiredSize) << endl; 
	}
}
