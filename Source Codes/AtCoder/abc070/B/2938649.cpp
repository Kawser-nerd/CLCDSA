#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    int A, B, C, D;
    cin >> A >> B;
    cin >> C >> D;
    int dist = min(B, D) - max(A, C);
    cout << max(dist, 0) << endl;
}