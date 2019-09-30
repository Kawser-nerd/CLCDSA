#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    int al = 0, bo = 0; 
    cin >> N;
    bool flag = true;
    vector<int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = N-1; i >= 0; i--){
        if(flag)al += a[i], flag = false;
        else al -= a[i], flag = true;
    }
    cout << al << endl;
    
}