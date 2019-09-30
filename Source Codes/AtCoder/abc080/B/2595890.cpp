#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin>>n;
    string s = to_string(n);
    int sum = 0;
    const int C = '0';
    for (int i=0; i<s.size(); ++i) {
        int c = s[i] - C;
        sum += c;
    }
    if (n % sum == 0) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    return 0;
}