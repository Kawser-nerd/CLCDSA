#include <iostream>

using namespace std;

int main(void) {
    string s;
    cin>>s;
    auto a = s.find('A');
    auto b = s.rfind('Z');
    cout<< (b-a+1) <<endl;
    return 0;
}