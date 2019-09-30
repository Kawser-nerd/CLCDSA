#include<iostream>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int y;
    cin >> y;
    string ans;
    if(y % 400 == 0){
        ans = "YES";
    }
    else if(y % 100 == 0){
        ans = "NO";
    }
    else if(y % 4 == 0){
        ans = "YES";
    }
    else{
        ans = "NO";
    }

    cout << ans << "\n";

    return 0;
}