#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    long N;
    long power = 1;
    cin >> N;

    for(long i = 1; i <= N; ++i){
        power *= i;
        power %= 1000000007;
    }
    cout << power << endl;
}