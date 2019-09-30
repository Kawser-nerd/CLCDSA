#include <iostream>
#include <algorithm>

inline void fastin(int &num) {
    bool neg = false;
    int c;
    num = 0;
    c = getchar_unlocked();
    if (c == '-') {
        neg = true;
        c = getchar_unlocked();
    }
    for (; (c > 47 && c < 58); c = getchar_unlocked()) num = num * 10 + c - 48;
    if (neg) num *= -1;
}

inline void fastout(int n) {
    int N = n, rev, count = 0;
    rev = N;
    if (N == 0) { putchar_unlocked('0'); putchar_unlocked('\n'); return ;}
    while ((rev % 10) == 0) { ++count; rev /= 10;}
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}
    while (rev != 0) { putchar_unlocked(rev % 10 + '0'); rev /= 10;}
    while (count--) putchar_unlocked('0');
}

int main(){
    int n, c, k; fastin(n); fastin(c); fastin(k);
    int t[n];
    for (int i = 0; i < n; ++i) fastin(t[i]);

    std::sort(t, t + n);

    int ans = 0;
    int beg = 0;
    while (beg < n){
        int end = beg;
        while (end - beg + 1 < c && t[end + 1] - t[beg] <= k){
            ++end;
            if (end == n - 1) break;
        }
        ++ans; beg = end + 1;
        if (beg == n - 1){
            ++ans; break;
        }
    }
    fastout(ans);
    
    return 0;
}