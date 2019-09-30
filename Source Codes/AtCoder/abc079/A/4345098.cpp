#include<iostream>
#include<vector>

using namespace std;

int main(){
    int X;
    int a[4];
    int cnt=0;
    cin >> X;
    for(int i = 0; i < 4; i++){
        a[i] =  X % 10;
        X /= 10; 
    }
    for(int i = 0; i < 2; i++){
        if(a[i] == a[i + 1] && a[i+1] == a[i+2])cnt++;
    }
    if(cnt > 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}