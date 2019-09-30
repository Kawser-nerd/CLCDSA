#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> t;
    int total {0};
    for (int i = 0; i < n; i++) {
        int T;
        cin >> T;
        t.push_back(T);
        total += t.at(i);
    }
    
    cin >> m;
    int p[m];
    int x[m];
    for (int j = 0; j < m; j++) {
        cin >> p[j] >> x[j];
    }
    
    for (int l = 0; l < m; l++) {
        cout << total - (t.at(p[l] - 1) - x[l]) << endl;
    } 
    return 0;
}