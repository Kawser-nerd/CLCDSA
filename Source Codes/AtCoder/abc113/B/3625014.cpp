#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    int T, A;
    cin >> T >> A;
    int tmp;
    cin >> tmp;
    int tmp_tmp = 1000 * T - tmp * 6;
    int num = abs(tmp_tmp - A * 1000);
    int ans = 0;
    if(N > 1){
        for(int i = 1; i < N; i++){
            cin >> tmp;
            tmp_tmp = 1000 * T - tmp * 6;
            if(abs(tmp_tmp - A * 1000) < num){
                num = abs(tmp_tmp - A * 1000);
                ans = i;
            }
        }
    }
    cout << ans + 1 << endl;
    
    return 0;
}