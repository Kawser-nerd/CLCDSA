#include <iostream>
using namespace std;
int main(void){
    char c;
    cin >> c;
    if(c == 'A') cout << 'T' << endl;
    if(c == 'T') cout << 'A' << endl;
    if(c == 'G') cout << 'C' << endl;
    if(c == 'C') cout << 'G' << endl;
    
    return 0;
}