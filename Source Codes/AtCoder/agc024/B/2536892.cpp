#include <iostream>
#include <vector>

using namespace std;

int n;
int pos[200001];

int main(){
    cin >> n;
    for (int i = 0;i < n; ++i) {
        int p;
        cin >> p;
        pos[p] = i;
    }

    int lis = 1;
    int is = 1;
    int lastp = pos[1];
    for (int i = 2; i <= n; ++i) {
        if (lastp < pos[i]) {
            is++;
        } else {
            lis = max(is, lis);
            is = 1;
        }
        lastp = pos[i];
    }
    lis = max(is, lis);

    cout << n - lis << endl;
}