#include<iostream>
using namespace std;

char s[50][50];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j >= 0; j--){
            cout << s[j][i];
        }
        cout << endl;
    }
}