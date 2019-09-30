#include <iostream>
#include <vector>
#include <string>
#include <strings.h>
#include <set>

using namespace std;

vector<int> solution;
int N;
int neededKeys[200];
vector < int > contain[200];
multiset <int> currentKeys;
bool open[200];
int opened = 0;
multiset<int> keys2RequiredKeys[201];

multiset <int> temporaryKeys;
bool analyzing[201];

bool canReach(int key){
	//cerr << "Intenta llegar a: " << key << endl;
	if ((currentKeys.count(key)) || (temporaryKeys.count(key))){
		return true;
	}

	if (analyzing[key]){
		return false;
	}
	analyzing[key] = true;
	//cout << "Claves desde la que puede llegar: " << keys2RequiredKeys[key].size() << endl;
	for (set<int>::iterator it = keys2RequiredKeys[key].begin(); it != keys2RequiredKeys[key].end(); it++){
		if (canReach(*it)){
			return true;
		}
	}
	return false;
}

bool canOpen(int box){
	if (open[box]){
		return false;
	}
	if (currentKeys.count(neededKeys[box]) == 0){
		return false;
	}
	if (currentKeys.count(neededKeys[box]) > 1){
		return true;
	}
	//Count pending
	int pending = 0;
	for (int i = 0; i < N; i++){
		if ((!open[i]) && (neededKeys[i] == neededKeys[box])){
			pending++;
		}
	}
	if (pending == 1){
		return true;
	} else {
		//cerr << "Hay mas de uno pendiente" << endl;
	}
	//Temmporary change
	open[box] = true;
	currentKeys.erase(currentKeys.find(neededKeys[box]));
	temporaryKeys.clear();
	for (int i = 0; i < contain[box].size(); i++){
		temporaryKeys.insert(contain[box][i]);
	}
	bzero(analyzing, 201 * sizeof(bool));
	bool reachable = canReach(neededKeys[box]);
	open[box] = false;
	currentKeys.insert(neededKeys[box]);
	return reachable;
}

void solve(){
	opened = 0;
	while (opened != N){
		bool changed = false;
		for (int i = 0; i < N; i++){
			if (canOpen(i)){
				solution.push_back(i + 1);
				changed = true;
				open[i] = true;
				currentKeys.erase(currentKeys.find(neededKeys[i]));
				for (int j = 0; j < contain[i].size(); j++){
					currentKeys.insert(contain[i][j]);
					keys2RequiredKeys[contain[i][j]].erase( keys2RequiredKeys[contain[i][j]].find(neededKeys[i]) );
				}
				opened++;
				break;
			} else {
				//cout << "No puede abrir " << i << endl;
			}
		}
		if (!changed){
			solution.clear();
			return;
		}
	}
}

bool checkSolution(vector<int> &solution, multiset<int> &keys){
	for (int i = 0; i < solution.size(); i++){
		if (keys.count(neededKeys[solution[i]-1]) == 0){
			cerr << "ERROR" << endl;
			return false;
		}
		keys.erase(keys.find(neededKeys[solution[i]-1]));
		for (int j = 0; j < contain[solution[i]-1].size(); j++){
			keys.insert(contain[solution[i]-1][j]);
		}
	}
	return true;
}

void clear(){
	for (int j = 0; j < 200; j++){
		keys2RequiredKeys[j].clear();
		contain[j].clear();
	}
	bzero(open, N * sizeof(bool));
	currentKeys.clear();
}

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		multiset<int> testInitialKeys;
		int K;
		cin >> K >> N;
		clear();
		for (int j = 0; j < K; j++){
			int key;
			cin >> key;
			currentKeys.insert(key);
		}
		testInitialKeys = currentKeys;
		for (int j = 0; j < N; j++){
			int Ti, Ki;
			cin >> neededKeys[j] >> Ki;
			for (int k = 0; k < Ki; k++){
				int key;
				cin >> key;
				contain[j].push_back(key);
				keys2RequiredKeys[key].insert(neededKeys[j]);
			}
		}
		solution.clear();
		solve();
		if (solution.size() == 0){
			cout << "Case #" << (i + 1) << ": IMPOSSIBLE" << endl; 
		} else {
			cout << "Case #" << (i + 1) << ": ";
			for (int j = 0; j < solution.size(); j++){
				cout << solution[j] << " ";
			}
			cout << endl;
		}
		/*if (solution.size()){
			if (checkSolution(solution, testInitialKeys)){
				cerr << "Solucion correcta" << endl;
			} else {
				cerr << "Sol. incorrecta" << endl;
			}
		}*/
	}
}
