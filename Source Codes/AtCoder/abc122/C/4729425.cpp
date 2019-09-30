#include <iostream>
using namespace std;
int main(void){
    int N, Q, l, r;
    int ans[100000] = {0};
    string str;
    cin >> N >> Q;
    cin >> str;

    for(int i = 0; i < N - 1; i++){
        ans[i+1] = ans[i] + (str[i] == 'A' && str[i+1] == 'C');
    }

    for(int i = 0; i < Q; i++){
        cin >> l >> r;
        cout << ans[r-1] - ans[l-1] << endl;
    }
    return 0;
}