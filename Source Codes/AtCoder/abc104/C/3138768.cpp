#include <iostream>
using namespace std;

int main() {
    int d, g, p[10], c[10];
    cin >> d >> g;
    for (int i = 0; i < d; i++) cin >> p[i] >> c[i];

    int solve_num = 10 * 100;

    for (int combination = 0b0; combination < (1 << d); combination++) {
        int const_score = 0, const_num = 0, not_used_max = -1;
        for (int i = 0; i < d; i++) {
            if ((combination >> i) & 1) {
                const_score += (i + 1) * 100 * p[i] + c[i];
                const_num += p[i];
            } else {
                not_used_max = i;
            }
        }

        int adjust = 0, adjust_num = 0;
        if (const_score < g) {
            adjust = (not_used_max + 1) * 100;
            adjust_num = ((g - const_score) / adjust) + ((g - const_score) % adjust ? 1 : 0);
            if (adjust_num >= p[not_used_max]) continue;
        }

        solve_num = min(solve_num, const_num + adjust_num);
    }

    cout << solve_num << endl;
}