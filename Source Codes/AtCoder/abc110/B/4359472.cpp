#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int N,M,X,Y;
    cin >> N >> M >> X >> Y;
    int a[N],b[M];
    for (int i = 0;i<N;i++){
        cin >> a[i];
    }
    for (int i = 0;i < M ;i++){
        cin >> b[i];
    }
    int c,d;
    sort(a,a+N);
    c = a[N -1];
    sort(b,b+M);
    d = b[0];
    if (c < d && c < Y && d > X){
        cout << "No War" << endl;
    }
    else{
        cout << "War" << endl;
    }

}