#include <iostream>

using namespace std;

int main(void) {
    string s, t;
    cin>>s>>t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end(), greater<char>());

    if (s.compare(t) < 0) {
        cout<<"Yes";
    } else {
        cout<<"No";
    }
    cout<<endl;
    return 0;
}