#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h,w;

int dx[] = {0,1,0,-1,0};


int main(void){
	cin >> h >> w;
	char board[h+2][w+2];
	for(int i = 0; i < h+2; ++i){
		for(int j = 0; j < w+2; ++j){
			board[i][j] = '.';
		}
	}
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			cin >> board[i+1][j+1];
		}
	}


	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j){
			if(board[i][j]=='#'){
				int k = 0;
				for(k = 0; k < 4; k++){
					if(board[i+dx[k]][j+dx[k+1]]=='#')	break;
				}
				if(k==4){
						cout << "No" << endl;
						return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}