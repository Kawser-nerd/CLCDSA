#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int N,a,b;
    cin >> N >> a >> b;
    int p = 0;
    int k,j;
    for (int i = 1; i <= N; i++){
        j = 0;
        k = i;
        while(k >= 1){
            j = j + (k % 10);
            k = k / 10;
        }
        if (a <= j && j <= b){
            p = p + i;
        }
    }
    cout << p << endl;
}