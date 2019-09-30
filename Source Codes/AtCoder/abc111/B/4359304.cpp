#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (int i = 0;i < 9;i++){
        if(N <= 111*(i + 1)){
            cout << 111*(i + 1) << endl;
            break;
        }
    }
}