#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<fstream>
#include<iostream>
#include<bitset>
#include<cassert>
#include<climits>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int find_digits(int a)
{
    int n = 0;
    while(a > 0) {
        a /= 10;
        ++n;
    }
    return n;
}

int cycle(int n, int d, int j)
{
    const int pow10[] = {1,
                         10,
                         100,
                         1000,
                         10000,
                         100000,
                         1000000,
                         10000000 
    };

    int a = n % pow10[j];
    int b = n / pow10[j];
    return a * pow10[d - j] + b;
}

void do_case(void)
{
    int A, B;
    cin >> A >> B;

    int d = find_digits(A);
    vector<int> used(B - A + 1, 0);

    unsigned long result = 0;

    for(int n = A; n < B; ++n) {
        if(used[n - A]) continue;

        unsigned long count = 1;
        for(int j = 1; j < d; ++j) {
            int m = cycle(n, d, j);
            if(m <= n || m > B) continue;
            if(used[m - A]) continue;

            ++count;
            used[m - A] = 1;
        }
        result += count * (count - 1) / 2;
    }

    cout << result << "\n";
}

void do_case_small(void)
{
    int A, B;
    cin >> A >> B;

    int d = find_digits(A);

    unsigned long result = 0;
    for(int n = A; n < B; ++n) {
        for(int m = n + 1; m <= B; ++m) {
            for(int j = 1; j < d; ++j) {
                if(cycle(n, d, j) == m) {
                    ++result;
                    break;
                }
            }
        }
    }
    cout << result << endl;
}

int main()
{
    freopen("input.data", "r", stdin);
    //freopen("output.data", "r", stdout);

    int cases;
    scanf("%d\n", &cases);
    int i = 1;
    do{
        printf("Case #%d: ", i);
        do_case();
        //do_case_small();
    }while(++i <= cases);

    return 0;
}
