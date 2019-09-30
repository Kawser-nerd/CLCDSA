#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool IsPlaced(string boardline) {
    return boardline.find('1') != string::npos;
}

bool CheckRow(string boardlines[8]) {
    for (int i = 0; i < 8; i++) {
        string line = boardlines[i];
        if (count(line.begin(), line.end(), '1') > 1) {
            return false;
        }
    }
    return true;
}

bool CheckColumn(string boardlines[8]) {
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        int n = stoi(boardlines[i], nullptr, 2);
        if ((sum & n) > 0){
            return false;
        }
        sum |= n;
    }
    return true;
}

int dx[] = {1, 1,-1,-1};
int dy[] = {1,-1, 1,-1};
bool checkDiagonal(string boardlines[8], int i, int j) {
    for (int n = 1; n < 8; n++) {
        for (int a = 0; a < 4; a++) {
            int x = j + n * dx[a], y = i + n * dy[a];
            if ((x < 0 || x > 7) || (y < 0 || y > 7)) continue;
            if (boardlines[y][x] == '1') return false;
        }
    }
    return true;
}

bool CheckDiagonal(string boardlines[8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (boardlines[i][j] == '1') {
                if (!checkDiagonal(boardlines, i, j)) return false;
            }
        }
    }
    return true;
}

void printBoardlines(string boardlines[8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (boardlines[i][j] == '1') cout << "Q";
            else cout << ".";
        }
        cout << endl;
    }
}

bool Check(string boardlines[8]) {
    return CheckRow(boardlines) && CheckColumn(boardlines) && CheckDiagonal(boardlines);
}

bool dfs(string boardlines[8], int depth) {
    if (depth == 8) return Check(boardlines);
    if (stoi(boardlines[depth], nullptr, 2) > 0) return dfs(boardlines, depth+1);

    for (int i = 0; i < 8; i++) {
        boardlines[depth][i] = '1';
        if (!Check(boardlines)) {
            boardlines[depth][i] = '0';
            continue;
        }
        bool result = dfs(boardlines, depth+1);
        if (result) return true;
        boardlines[depth][i] = '0';
    }

    return false;
}

int main() {
    string boardlines[8];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            if (c == 'Q') {
                boardlines[i] += '1';
            } else {
                boardlines[i] += '0';
            }
        }
    }

    if (dfs(boardlines, 0)) {
        printBoardlines(boardlines);
    } else {
        cout << "No Answer" << endl;
    }

    return 0;
}