#include<iostream>
#include <string>
using namespace std;

/*
int main() {
    float w, h;
    cin >> w >> h;
    float aspe;
    aspe = w/h;
    float wide, tall;
    wide = 4/3;
    tall = 16/9;
    if (aspe == wide) cout << "4:3" << endl;
    if (aspe == tall) cout << "16:9" << endl;
}
 */
int main(){
    int w, h;
    cin >> w >> h;
    if((h / 3) * 4 == w) cout << "4:3" << endl;
    else cout << "16:9" << endl;
    return 0;
}