#include <iostream>
#include <string>
using namespace std;

int main(){
    string w;
    cin >> w;

    for(int i = 0;w[i];++i){
        if((w[i] == 'a') || (w[i] == 'i') || (w[i] == 'u') || (w[i] == 'e') || (w[i] == 'o'))
            continue;
        cout << w[i];
    }
    cout << endl;
}