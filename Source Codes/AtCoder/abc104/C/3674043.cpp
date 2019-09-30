#include <iostream>
#include <cstdlib>
#include <queue>
#include <math.h>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
using namespace std;

int main()
{
    int ans = 2000000;
    int d;
    bool b = false;
    int g, score, q;
    cin >> d >> g;
    vector<int> p(d+1, 0);
    vector<int> c(d+1, 0);
    for(int i=1; i<=d; ++i){
        cin >> p[i] >> c[i];
    }
    for(int i=0; i<(int)(pow(2, d)); ++i){
        bitset<10> complete = static_cast<bitset<10>>(i);
        score = 0;
        q = 0;
        b = false;
        // cout << complete << endl;
        // complete bonus
        for(int j=d-1; j>=0; --j){
            if(complete[j] == 1){
                score += 100 * (j+1) * p[j+1] + c[j+1];
                q += p[j+1];
            }
            if(score >= g){
                ans = min(ans, q);
                b = true;
            }
        }
        if(b){
            // cout << q << endl;
            continue;
        }
        // normal
        for(int j=d-1; j>=0; --j){
            if(complete[j] == 0){
                for(int k=1; k<p[j+1]; ++k){
                    score += 100 * (j+1);
                    q++;
                    if(score >= g){
                        ans = min(ans, q);
                        b = true;
                        break;
                    }
                }
            }
            if(b){
                // cout << q << endl;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}