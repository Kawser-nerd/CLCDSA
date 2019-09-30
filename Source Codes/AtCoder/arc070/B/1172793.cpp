#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <ctime>
using namespace std;


int main() {



    int n, k;
    cin >> n;
    cin >> k;

    time_t start_t = time(0);
    struct tm * start = localtime(&start_t);

    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<vector<int> > prefix(n+1, vector<int>(k+1));

    prefix[0][0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=k; j++) {
            int v = prefix[i][j];
            if(v == 1) {
                prefix[i+1][j] = 1;
                if(j+a[i] <=k){
                    prefix[i+1][j + a[i]] = 1;
                }
            }
        }
    }
    time_t end_t = time(0);
    struct tm * end = localtime(&end_t);
    
   // cout << double(end_t - start_t) << endl;
    
    vector<vector<int> > suffix(n+1, vector<int>(k+1));
    suffix[n][0] = 1;
    for(int i=n-1; 0<=i; i--) {
        for(int j=0; j<=k; j++) {
            int v = suffix[i+1][j];
            if(v == 1) {
                suffix[i][j] = 1;
                if(j+a[i]<=k) {
                    suffix[i][j+a[i]] = 1;
                }
            }
        }
    }

    // cumulative sums
    int c_suffix_i_plus_1[5001];

    int res = 0;
    for(int i=0; i<n; i++) {
        if(k<=a[i])
            continue;
        c_suffix_i_plus_1[0] = 0;
        for(int j=0; j<k; j++) {
            bool is_in = suffix[i+1][j] > 0;
            c_suffix_i_plus_1[j+1] = c_suffix_i_plus_1[j] + is_in;
        }
        bool ok = true;
        for(int j=0; j<k; j++) {
            int s = prefix[i][j];
            if(s == 1) {
                int start = k-a[i]-j;
                if(start<0) start = 0;
                int stop = k-j;
                if (c_suffix_i_plus_1[stop] - c_suffix_i_plus_1[start] > 0){
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            res++;

        }
    }
    cout << res << endl;

}