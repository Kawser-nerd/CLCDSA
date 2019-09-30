#include <iostream>
#include <vector>
using namespace std;

int main(){
    char a;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> a;
            if(i == j)cout << a;
        }
    }
    cout << endl;
}