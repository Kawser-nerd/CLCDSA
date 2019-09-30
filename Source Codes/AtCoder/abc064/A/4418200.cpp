#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define LL long long 

int main(){
    int r,g,b;
    LL ans = 0;
    cin >> r >> g >> b;
    int tmp = 100 * r + 10 * g + b;
    if(tmp % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}