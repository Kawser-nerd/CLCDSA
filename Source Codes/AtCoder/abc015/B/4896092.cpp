#include<iostream>
#include<string>
using namespace std;

int main() {
    int n;
    int sum = 0;
    int num = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        if (tmp != 0) num++;
    }
    cout << sum / num + (sum % num > 0 ? 1 : 0) << endl;
}