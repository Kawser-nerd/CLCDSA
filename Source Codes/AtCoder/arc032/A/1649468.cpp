//
// Created by Akifumi Ohata on 2017/10/03.
//


#include<iostream>
#include <vector>
#include <numeric>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

using ll =  long long int;

/// return set of prime and pow
/// ?????????????????
/// if int N =64*17; return (2,6) (1,17)
/// if int N =17; return empty vector

std::vector<std::pair<int, int>> prime_division(int N) {

    std::vector<std::pair<int, int>> division_result;

    int limit = ((int) (sqrt(N)) + 2);
    for (int element = 2; element < limit; element++) {

        bool enable_divide = true;
        int divided_time = 0;

        while (enable_divide) {

            if ((N % element) == 0) {
                divided_time += 1;
                N /= element;
            } else {
                enable_divide = false;

            }
        }

        if (divided_time > 0) {
            division_result.emplace_back(std::make_pair(element, divided_time));
        }
    }

    return division_result;

}


int main() {
    ios::sync_with_stdio(false);

    int N, M;

    ll MOD = 1000000007;


    cin >> N;

    int sum = (N * (N + 1)) / 2;


    vector<pair<int, int>> ans;
    ans = prime_division(sum);


    if (ans.empty() && sum != 1) {
        cout << "WANWAN" << endl;

    } else {

        cout << "BOWWOW" << endl;

    }
    return 0;
}