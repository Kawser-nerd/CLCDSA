#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n%2==0){
        cout << n*(n-2)/2 << endl;
        for(int i = 1;i<n+1;i++){
            for(int j = i+1;j<n+1;j++){
                if(i+j != n+1){
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    else{
        cout << (n-1)*(n-1)/2 << endl;
        for(int i = 1;i<n+1;i++){
            for(int j = i+1;j<n+1;j++){
                if(i+j != n){
                    cout << i << " " << j << endl;
                }
            }
        }
    }
}