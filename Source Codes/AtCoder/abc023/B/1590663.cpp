#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string S;
    cin >> N >> S;
    string T = "b";
    if(S == T){
        cout << 0 << endl;
        return 0;
    }
    for(int i=1; i<=N; i++){
        if(i % 3 == 1){
            T = "a" + T;
            T = T + "c";
        }else if(i % 3 == 2){
            T = "c" + T;
            T = T + "a";
        }else{
            T = "b" + T;
            T = T + "b";
        }
        if(S == T){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}