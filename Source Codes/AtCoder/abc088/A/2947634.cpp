#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {

    int N, A;
    cin >> N;
    cin >> A;

    for(int i = 0; i <= A; ++i){
        if( (N - i)%500 == 0 ){
            cout << "Yes" << endl;
            return 0;
        } 
    }

    cout << "No" << endl;
    return 0;
}