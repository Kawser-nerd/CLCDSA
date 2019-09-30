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
    int N,tmp,a;
    int s,g;
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    s = max(A,C);
    g = min(B,D);
    if(s < g){
        cout << g - s << endl;
    }else{
        cout<< 0 << endl;
    }
    
}