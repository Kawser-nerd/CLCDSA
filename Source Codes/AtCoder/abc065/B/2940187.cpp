#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {

    int a[100000];
    int N;
    int res = 0;
    int nextNum;
    set<int> bottuns;

    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }

    nextNum = 1;
    bottuns.insert(nextNum);
    while(true){
        nextNum = a[nextNum];
        ++res;
        if(nextNum == 2){
            cout << res << endl;
            return 0;
        }
        if(bottuns.count(nextNum == 1) || res == N){
            break;
        }
        bottuns.insert(nextNum);
    }

    cout << -1 << endl;
    return 0;

}