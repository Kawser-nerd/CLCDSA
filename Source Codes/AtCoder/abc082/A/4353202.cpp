#include<iostream>
#include<cmath>
#include<string>
#include<vector>

using namespace std;
#define ll long long 

int  main(){
    int a,b;
    cin >> a >> b;
    if((a+b)%2 ==0){
        int ans = (a+b)/ 2;
        cout << ans << endl;
    }else{
        int ans = (a+b)/ 2 + 1;
        cout << ans << endl;
    }
}