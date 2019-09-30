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
    int A, B, C;
    cin >> A >> B >> C;
    if(A != B){
        if(B == C){
            cout << A << endl; 
        }else{
            cout << B << endl;
        }
    }else{
        cout << C << endl;
    }
}