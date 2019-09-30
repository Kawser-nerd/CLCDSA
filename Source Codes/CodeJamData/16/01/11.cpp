#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;
typedef long long ll;

bitset<10> seen;

void process(int m) {
    while (m != 0) {
        seen[m%10] = true;
        m /= 10;
    }
}

int main()
{
    int nt;
    cin >> nt;
    for (int t=1; t<=nt; t++)
    {
        ll n;
        cout << "Case #" << t << ": ";
        ll answer;
        cin >> n;
        seen.reset();
        bool okay = false;
        for (int i=1; i<=1000; i++) {
            process(n*i);
            if (seen.count() == 10) {
                answer = n*i;
                okay = true;
                break;
            }
        }
        if (okay)
            cout << answer << endl;
        else
            cout << "INSOMNIA" << endl;
    }
}
