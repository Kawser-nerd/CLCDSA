#include <iostream>
using namespace std;
int X = 200001;
int bt[200001];

int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bt[i];
        i -= i & -i;
    }
    return s;
}

void update(int i, int a) {
    while (i <= X) {
        bt[i] += a;
        i += i & -i;
    }
}

int main(void){
    // Your code here!
    int Q;
    
    cin >> Q;
    
    int f;
    int x;
    for (int q = 0; q < Q; ++q) {
        cin >> f >> x;
        if (f == 1) {
            update(x, 1);
        } else {
            int l = 0;
            int r = X - 1;
            
            while (l != r) {
                int m = (l + r) / 2;
                if (sum(m) < x) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            
            cout << l << endl;
            update(l, -1);
        }
    }
}