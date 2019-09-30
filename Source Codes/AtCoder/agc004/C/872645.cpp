#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 501;

int main()
{
	int H, W;
	cin >> H >> W;
	string g[N];
	for(int i = 0; i != H; ++i){
		cin >> g[i];
	}
	for(int i = 0; i != H; ++i){
		for(int j = 0; j != W; ++j){
			if(g[i][j] == '#' || j == 0){
				cout << '#';
			}
			else if(i % 2 == 0 && j != W - 1){
				cout << '#';
			}
			else{
				cout << '.';
			}
		}
		cout << endl;
	}
	for(int i = 0; i != H; ++i){
		for(int j = 0; j != W; ++j){
			if(g[i][j] == '#' || j == W - 1){
				cout << '#';
			}
			else if(i % 2 == 1 && j != 0){
				cout << '#';
			}
			else{
				cout << '.';
			}
		}
		cout << endl;
	}
}