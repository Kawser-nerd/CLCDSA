#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(){
    int N, r[100000], l[100000];
    int total= 0;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> r[i] >> l[i];
        total += l[i] - r[i] + 1;
    }
    cout << total << endl;
}