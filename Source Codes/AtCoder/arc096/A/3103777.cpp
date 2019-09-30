#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main(){
    long A, B, C;
    int X, Y;
    long total = 40000000000;
    int max_num;

    cin >> A >> B >> C >> X >> Y;

    max_num = max(X, Y);

    for(int i = 0; i <= max_num; ++i){
        int xtmp = max(0, X-i);
        int ytmp = max(0, Y-i);

        long tmp = A * xtmp + B * ytmp + 2*C*i;
        total = min(tmp, total);
    }
    cout << total << endl;
}