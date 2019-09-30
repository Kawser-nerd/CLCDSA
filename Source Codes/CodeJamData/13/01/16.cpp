#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool checkWin(const vector<string> &board, char c){
	for (int i = 0; i < board.size(); i++){
		bool win = true;
		for (int j = 0; j < 4; j++){
			if ((board[i][j] != c) && (board[i][j] != 'T')){
				win = false;
				break;
			}
		}
		if (win){
			return true;
		}
	}
	for (int i = 0; i < board.size(); i++){
		bool win = true;
		for (int j = 0; j < 4; j++){
			if ((board[j][i] != c) && (board[j][i] != 'T')){
				win = false;
				break;
			}
		}
		if (win){
			return true;
		}
	}
	bool win = true;
	for (int i = 0; i < board.size(); i++){
		if ((board[i][i] != c) && (board[i][i] != 'T')){
			win = false;
			break;
		}
	}
	if (win){
		return true;
	}

	win = true;
	for (int i = 0; i < board.size(); i++){
		if ((board[i][3 - i] != c) && (board[i][3 - i] != 'T')){
			win = false;
			break;
		}
	}
	if (win){
		return true;
	}
	return false;
}

bool checkFinish(const vector<string> &board){
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (board[i][j] == '.'){
				return false;
			}
		}
	}
	return true;
}

string solve(const vector<string> &board){
	if (checkWin(board, 'O')){
		return "O won";
	} else if (checkWin(board, 'X')){
		return "X won";
	} else if (checkFinish(board)){
		return "Draw";
	} else {
		return "Game has not completed";
	}
}

int main(){
	int T;
	cin >> T;
	for (int i = 0; i < T; i++){
		vector<string> board;
		for (int j = 0; j < 4; j++){
			string line;
			cin >> line;
			board.push_back(line);
		}
		cout << "Case #" << (i + 1) << ": " << solve(board) << endl; 
	}
}
