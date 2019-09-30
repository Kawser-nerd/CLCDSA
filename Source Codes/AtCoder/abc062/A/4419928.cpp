#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define LL long long 

int main(){
    int r,g,b;
    int x, y;
    cin >> x >> y;
    if(x == 2){
        if(y == 2){
            cout << "Yes" << endl;
        }else
        {
            cout<< "No" << endl;
        }  
    }else if(x == 4 || x == 6 || x == 9 || x == 11){
        if(y == 4 || y == 6 || y == 9 || y == 11){
            cout << "Yes" << endl;
        }else
        {
            cout<< "No" << endl;
        }  
    }else{
        if(y != 4 && y != 6 && y != 9 && y != 11 && y != 2){
            cout << "Yes" << endl;
        }else
        {
            cout<< "No" << endl;
        }  
    }
}