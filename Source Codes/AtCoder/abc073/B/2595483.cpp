#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin>>n;
    int x = 0;
    for (int i=0; i<n; ++i) {
        int l, r;
        cin>>l>>r;
        int num = r - l + 1;
        x += num;
    }
    cout<<x<<endl;
    return 0;
}