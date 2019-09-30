#include <iostream>

using namespace std;

int main(void)
{
    int R;
    cin >> R;
    if(1200 > R){
        cout << "ABC" << endl;
    }else if(2800 > R){
        cout << "ARC" << endl;
    }else {
        cout << "AGC" << endl;
    }
    return 0;
}