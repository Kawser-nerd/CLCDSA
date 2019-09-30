#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int N;
    cin >> N;
    int ans;
    if(105 > N){
        ans = 0;
    }
    else if(135 > N){
        ans = 1;
    }
    else if(165 > N){
        ans = 2;
    }
    else if (189 > N){
        ans = 3;
    }
    else if (195 > N){
        ans = 4;
    }
    else{
        ans = 5;
    }
    cout << ans << endl;

}