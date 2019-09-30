#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
vector<int> L;
vector<int> D;


int main(void){
    // Your code here!
    cin >> n >> m;
    L.resize(m);
    for(int i = 0; i < m ; i++){
        cin >> L[i];
    }
    
    sort(L.begin(), L.end(), greater<int>());
    D.resize(m-1);
    
    for(int i = 0; i < m-1; i++){
        D[i] = abs(L[i] - L[i+1]);
    }
    
    sort(D.begin(), D.end(), greater<int>());
    
    int cnt = 0;
    for(int i = 0; i < n-1; i++){
        if(i == m - 1) break;
        cnt += D[i];
    }
    
    cout << L[0] - L[m-1] - cnt << endl;

}