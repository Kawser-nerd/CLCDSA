#include <iostream>
#include <string>
#include <set>
#include <math.h>
using namespace std;

int main(){
    int N, X;
    int m[110];
    int total = 0;
    int m_min = 1000;

    cin >> N >> X;
    for(int i =0; i < N; ++i){
        cin >> m[i];
        total += m[i];
        m_min = min(m_min, m[i]); 
    }
    cout << N + ( X - total ) / m_min << endl;
}