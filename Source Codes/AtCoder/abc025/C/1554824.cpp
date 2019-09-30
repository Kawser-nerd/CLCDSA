#include <iostream>
using namespace std;

typedef pair<int, int> P;

int a[2][3] = {0}; 
int b[3][2] = {0};
int table[3][3] = {0};
int sumS = 0;

int dfs(int order){
    if(order == 9){
        int x = 0, y = 0;
        for(int i = 0; i < 2; ++i)
        for(int j = 0; j < 3; ++j){
            if(table[i][j] == table[i+1][j]) x+=a[i][j];
            else y+=a[i][j];
        }
        for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 2; ++j){
            if(table[i][j] == table[i][j+1]) x+=b[i][j];
            else y+=b[i][j];
        }
        return x - y;
    }
    int ans;
    int flag = order & 1;
    if(flag){
        int minDiff = INT_MAX;
        for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j){
            if(table[i][j] == 0){
                table[i][j] = -1;
                minDiff = min(minDiff, dfs(order+1));
                table[i][j] = 0;
            }
        }
        ans = minDiff;
    }else{
        int maxDiff = INT_MIN;
        for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j){
            if(table[i][j] == 0){
                table[i][j] = 1;
                maxDiff = max(maxDiff, dfs(order+1));
                table[i][j] = 0;
            }
        }
        ans = maxDiff;
    }
    return ans;
}

int main(){
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> a[i][j];
            sumS += a[i][j];
        }
    }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 2; ++j){
            cin >> b[i][j];
            sumS += b[i][j];
        }
    }
    int score = dfs(0);
    cout << (sumS + score) / 2 << endl;
    cout << (sumS - score) / 2 << endl;

    return 0;
}