#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    string s;
    cin>>s;
    int num = s.size() - 2;
    s.replace(s.begin()+1, s.end()-1, to_string(num));
    cout<<s<<endl;
    return 0;
}