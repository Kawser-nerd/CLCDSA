#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0;i < N;i++){
        cin >> a[i];
    }
    sort(a,a+N);
    int m = a[N-1];
    int p = 0;
    for (int i = 0;i < N-1;i++){
        p = p + a[i];
    }
    cout << p + m/2 << endl;

}