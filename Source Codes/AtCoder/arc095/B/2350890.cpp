#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sys/time.h>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>

using namespace std;

void solve(long long n, vector<long long> a){
    sort(a.begin(), a.end());
    long long ai = a.back();
    a.pop_back();
    std::cout << ai << " ";
    long long aj1, aj2;
    for (int i = 0; i < a.size(); i++) {
        if (ai/2 <= a[i]) {
            aj1 = a[i];
            if (i == 0) {
                std::cout << a[i] << std::endl;
                return;
            } else {
                aj2 = a[i-1];
                break;
            }
        } else if (i == a.size()-1) {
            std::cout << a[i] << std::endl;
            return;
        }
    }
    if (abs(aj1 - (ai/2.0)) > abs(aj2 - (ai/2.0))) {
        std::cout << aj2 << std::endl;
    } else {
        std::cout << aj1 << std::endl;
    }
}

int main(){	
    struct timeval start,end;
    long long span;
    gettimeofday(&start,NULL);

    long long n;
    scanf("%lld",&n);
    vector<long long> a(n-1+1);
    for(int i = 0 ; i <= n-1 ; i++){
    	scanf("%lld",&a[i]);
    }
    solve(n, a);

    gettimeofday(&end,NULL);
    span = (end.tv_sec -start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    std::cerr << "--Total Time: " << span/1000 << "ms" << endl;
    return 0;
}