#include <iostream>

using namespace std;

int main(void) {
    string s;
    cin>>s;
    s.replace(s.begin(), s.begin()+4, "2018");
    cout<<s<<endl;
    return 0;
}