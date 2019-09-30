#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int N;
    cin >> str;
    cin >> N;

    int buff = 0;
    int x = 0, y = 0;
    for(int i = 0; i < str.size(); ++i){
        switch(str[i]){
            case 'L':
                --x;
                break;
            case 'R':
                ++x;
                break;
            case 'U':
                ++y;
                break;
            case 'D':
                --y;
                break;
            case '?' :
                ++buff;
                break;
            default :
                break;
        }
    }
    int ans;
    if(abs(x) + abs(y) - buff < 0){
        ans = abs(abs(x) + abs(y) - buff) % 2;
    }else{
        ans = abs(x) + abs(y) - buff;
    }
    if(N == 2) cout << ans << endl;
    else cout << abs(x) + abs(y) + buff << endl;
    
    return 0;
}