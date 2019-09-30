#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int N,T;
    cin >> N >> T;
    int c[N],t[N];
    for (int  i = 0;i< N;i++){
        cin >> c[i] >> t[i];
    }
    int p = 1000000000;
    bool flag = false;
    for (int i = 0;i<N;i++){
        if (t[i] <= T){ 
            p = min(p,c[i]);
            flag = true;
        }
    }
    if (flag == true){
        cout << p << endl;
    }
    else{
        cout << "TLE" << endl;
    }
}