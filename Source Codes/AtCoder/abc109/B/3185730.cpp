#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    int N;

    cin >> N;

    vector<string> W(N);

    for(int i = 0; i < N ; ++i )cin >> W[i];

    bool flag = true; // ???????????????

    for(int i = 1; i < N ; ++i ) {
        if(!flag) break;
        for( int j = 0; j < i ; ++j ) {
            if(W[i] == W[j]) { // W[i]???????????
                flag = false;
                break;
            }
        }
        if(W[i].front() != W[i-1].back()) // ??????????????????????
            flag = false;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}