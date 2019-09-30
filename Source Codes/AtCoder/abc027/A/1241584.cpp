#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> l(3,0);
    cin >> l[0] >> l[1] >> l[2];
    sort(l.begin(), l.end());

    if(l[0] == l[1]){
        cout << l[2] << endl;
    }else{
        cout << l[0] << endl;
    }
}