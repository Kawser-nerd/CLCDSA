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
    int a,b,c;
    cin >> a >> b >>c;
    if(b-a == c-b){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}