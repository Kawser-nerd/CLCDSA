#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    
    queue< pair<int, int>> q;
    pair<int, int> q0(0, A);
    q.push( q0 );
    int base[6] = {1, -1, 5, -5, 10, -10};
    int flag = 0;

    if(q.front().second == B){
        cout << 0 << endl;
        return 0;
    }

    while(q.front().first < 10){
        int first = q.front().first;
        int second = q.front().second;

        for(int i = 0; i < 6; ++i){
            if(second + base[i] == B){
                flag = 1;
                break;
            }
            pair<int, int> temp(first+1, second + base[i]);
            q.push(temp);
        }
        if(flag) break;
        q.pop();
    }

    cout << q.front().first+1 << endl;
    return 0;
}