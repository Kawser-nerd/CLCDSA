#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int A, B, C;
    int i = 1;
    int rem;

    cin >> A >> B >> C;
    set<int> rems;

    while(true){
        rem = (A * i) % B;
        if(rem == C){
            cout << "YES" << endl;
            return 0;
        }
        if(rems.count(rem) == 1){
            break;
        }
        rems.insert(rem);
        ++i;
    }

    cout << "NO" << endl;
    return 0;
}