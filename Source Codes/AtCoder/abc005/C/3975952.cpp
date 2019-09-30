#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <bitset>
#include <string>
#include <array>

using namespace std;

int main()
{
    int t, n, m;
    cin >> t >> n;
    vector<int> a(n);
    bool isSold[n];
    for (int i=0; i<n; ++i){
        cin >> a[i];
        isSold[i] = false;
    }
    cin >> m;
    vector<int> b(m);
    for (int i=0; i<m; ++i){
        cin >> b[i];
    }

    string answer = "yes";
    bool check = false;
    const int inf = 10000;
    int min_dt = inf;
    int itr = 0;
    for (int i=0; i<m; ++i){
        check = false;
        min_dt = inf;
        for (int j=0; j<n; ++j){
            if(!isSold[j] && a[j] <= b[i] && b[i] <= a[j] + t && (a[j] + t - b[i]) < min_dt){
                min_dt = a[j] + t - b[i];
                itr = j;
                check = true;
            }
            if(j == n-1 && !check){
                answer = "no";
            }
            if(check){
                isSold[itr] = true;
            }
        }
    }
    cout << answer << endl;
    return 0;
}