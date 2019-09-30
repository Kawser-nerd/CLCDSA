#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int N ;
    int a[120];
    cin >> N;
    for (int i = 0;i < N; i++){
        cin >> a[i];
    }
    int p = 0; 
    sort(a,a + N, greater<int>());
    for (int i = 0; i < N; i++){
        if(i % 2 == 0){
            p = p + a[i];
        } 
        else{
            p = p - a[i];
        }

    }
    cout << p << endl;

}