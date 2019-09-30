#include <iostream>

using namespace std;

int main(void) {
    const int N = 26;
    const int C = 'a';
    int map[N] = {};
    string s;
    cin>>s;
    int len = s.size();
    for (int i=0; i<len; ++i) {
        int c = s[i] - C;
        map[c] = 1;
    }
    bool hit = false;
    for (int i=0; i<N; ++i) {
        if (map[i] == 0) {
            char c = i + C;
            cout<<c<<endl;
            hit = true;
            break;
        }
    }
    if (!hit) {
        cout<<"None"<<endl;
    }
    return 0;
}