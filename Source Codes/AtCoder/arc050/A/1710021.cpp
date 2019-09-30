#include <iostream>
using namespace std;
int main(void){
    char x, y;cin >> x >> y;cout << ((x - 'A') == (y - 'a') ? "Yes" : "No") << endl;
    return 0;
}