#include<iostream>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int y;
    cin >> y;
    string ans;
    if(y % 400 == 0){
        cout << "YES" << "\n";
    }
    else if(y % 100 == 0){
        cout << "NO" << "\n";
    }
    else if(y % 4 == 0){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }

    return 0;
}