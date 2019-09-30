#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    int res;
    int x,y;

    cin >> N;
    res = N / 15;
    x = 800 * N;
    y = 200 * res;

    cout << x - y << endl;


}