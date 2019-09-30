#include <iostream>
#include <set>

using namespace std;

int main(void) {
    string s;
    cin>>s;
    set<char> sc;
    for (int i=0; i<s.size(); ++i) {
        sc.insert(s[i]);
    }
    if (s.size() == sc.size()) {
        cout<<"yes"<<endl;
    } else {
        cout<<"no"<<endl;
    }
    return 0;
}