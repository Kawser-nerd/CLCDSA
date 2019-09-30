#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    long n,m;
    cin >> n;
    cin >> m;

    long scc_count = 0;
    long tmp_n = n;
    long tmp_m = m;

    while(tmp_n > 0 && tmp_m > 1){
        ++scc_count;
        tmp_n -= 1;
        tmp_m -= 2;
    }

    if(tmp_m > 3){
        scc_count += tmp_m / 4;
    }

    cout << scc_count << endl;

    return 0;
}