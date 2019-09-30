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
    cin >> N;
    tmp = N % 10;
    a = N /100;
    if(a == tmp){
        cout << "Yes" <<endl;
    }else{
        cout << "No" <<endl;
    }
    
}