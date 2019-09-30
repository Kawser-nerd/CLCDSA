#include <iostream>
using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    int counter = 0;
    if(0 <= (int)S.find("a") && S.find("a") <= 2){
        counter++;
    }
    if(0 <= (int)S.find("b") && S.find("b") <= 2){
        counter++;
    }
    if(0 <= (int)S.find("c") && S.find("c") <= 2){
        counter++;
    }

    if(counter == 3){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }
    return 0;
}