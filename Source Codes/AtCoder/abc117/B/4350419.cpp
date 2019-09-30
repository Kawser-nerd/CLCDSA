#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main() {
    int N;
    cin >> N;
    int l[N];
    for (int i = 0;i< N;i++){
        cin >> l[i]; 
    }
    sort(l,l+N);
    int a = l[N-1];
    int b = 0;
    for (int i = 0;i < N-1;i++){
        b = b + l[i];
    }
    if (a < b){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

}