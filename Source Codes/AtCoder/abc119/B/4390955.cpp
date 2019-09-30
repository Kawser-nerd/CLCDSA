#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<string>

using namespace std;

#define ll long long

int main(){
    int N;
    double sum = 0;
    cin >> N;
    vector<double> x(N);
    vector<string> u(N);
    for(int i = 0; i < N; i++){
        cin >> x[i] >> u[i];
        if(u[i] == "BTC"){
            sum += x[i] * 380000;
        }else{
            sum += x[i];
        }
    } 
    cout << sum << endl;
    
}