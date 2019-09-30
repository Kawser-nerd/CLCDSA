#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int N,d[110];
    cin >> N;
    for (int i = 0;i < N;i++){
        cin >> d[i];
    }

    int num[110];

    for (int i = 0;i <= 99;i++){
        num[i] = i + 1;
    }
    int p = 0;
    for (int i = 0;i <= 99;i++){
        for (int j = 0;j < N;j++){
            if (d[j] == num[i]){
                p = p + 1;
                break;
            }
        }
    }
    cout << p << endl;
}