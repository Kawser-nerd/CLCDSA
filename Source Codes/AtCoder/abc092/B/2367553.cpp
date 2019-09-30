#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int n,d,x;
    cin >> n >> d >> x;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; ; j++) {
            if(j * a[i] + 1 <= d) {
                sum++;
            } else {
                break;
            }
        }
    }

    cout << (sum + x) << endl;
}