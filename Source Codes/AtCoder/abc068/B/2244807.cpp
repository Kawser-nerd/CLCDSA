#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    int res = 0;
    int ans = 1;
    for (int i = 1; i <= N; ++i){
        int count = 0;
        int j = i;
        while(true){
            if (j % 2 != 0) break;
            else {
                j /= 2;
                ++count;
            }
        }
        if (count > res){
            res = count;
            ans = i;
        }
    }
    cout << ans << endl; 
}