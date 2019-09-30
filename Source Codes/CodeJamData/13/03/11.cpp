

//#define ONLINE_JUDGE

#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <climits>
#include <cfloat>
#include <cctype>
#include <sstream>


using namespace std;

FILE * file = fopen("all", "w");

inline void read(int & n) {
    scanf("%d", & n);
}

class Big {
private:
    static const int base, biggest;
    typedef deque<int> Digits;

public:////////////////////
    Digits d;

    void inc(int startPos = 0) {    // startPos <= d.size()
        int i;
        for (i = startPos; i != d.size(); ++i) {
            if (++d[i] != base)
                return;
            d[i] = 0;
        }
        d.push_back(1);
    }

    void removeStartZeros() {
        while (! d.empty() && d.back() == 0)
            d.pop_back();
    }

    void dec(int startPos = 0) {    // startPos < d.size()
        for (int i = startPos; ; ++i) {
            if (--d[i] >= 0) {
                removeStartZeros();
                return;
            }
            d[i] = biggest;
        }
    }

    void multiplyBy2() {
        int r = 0;
        for (int i = 0; i != d.size(); ++i) {
            d[i] = d[i] * 2 + r;
            if (d[i] >= base) {
                d[i] -= base;
                r = 1;
            } else
                r = 0;
        }
        if (r != 0)
            d.push_back(1);
    }
public:
    void operator+=(const Big & n) {
        int size = min(d.size(), n.d.size());
        int r = 0;
        for (int i = 0; i != size; ++i) {
            d[i] += n.d[i] + r;
            if (d[i] >= base) {
                d[i] -= base;
                r = 1;
            } else
                r = 0;
        }
        if (n.d.size() > size)
            d.insert(d.end(), n.d.begin() + size, n.d.end());
        if (r != 0)
            inc(size);
    }

    void operator-=(const Big & n) {    // n <= *this
        int r = 0;
        for (int i = 0; i != n.d.size(); ++i) {
            d[i] -= n.d[i] + r;
            if (d[i] < 0) {
                d[i] += base;
                r = 1;
            } else
                r = 0;
        }
        if (r != 0)
            dec(n.d.size());
        else
            removeStartZeros();
    }

    bool subtract(const Big & n, int startPos = 0) {
        // if (n > *this) { *this is undefined; return false; } else { *this -= n; return true; }
        if (d.size() < n.d.size() + startPos)
            return false;
        int r = 0;
        for (int i = 0; i != n.d.size(); ++i) {
            int j = startPos + i;
            d[j] -= n.d[i] + r;
            if (d[j] < 0) {
                d[j] += base;
                r = 1;
            } else
                r = 0;
        }
        if (r != 0) {
            int j = startPos + n.d.size();
            if (j == d.size())
                return false;
            dec(j);
        } else
            removeStartZeros();
        return true;
    }

    void operator*=(int n) {  // n < base
        int r = 0;
        for (int i = 0; i != d.size(); ++i) {
            d[i] = d[i] * n + r;
            r = d[i] / base;
            d[i] %= base;
        }
        if (r != 0)
            d.push_back(r);
    }

    void operator*=(const Big & n) {
        Big original = *this;
        d.clear();
        for (int i = n.d.size() - 1; i >= 0; --i) {
            Big cur = original;
            cur *= n.d[i];
            d.push_front(0);
            *this += cur;
        }
    }


    void print() const {
        for (int i = d.size() - 1; i >= 0; --i)
            fprintf(file, "%d", d[i]);
        fputc('\n', file);
    }

    bool isPalindrome() {
        for (size_t i = 0, j = d.size() - 1; i < j; ++i, --j) {
            if (d[i] != d[j])
                return false;
        }
        return true;
    }

    void printIfPalindrome() {
        if (isPalindrome())
            print();
    }
};

const int Big::base = 10;
const int Big::biggest = Big::base - 1;



int main()
{
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);

    //freopen("all", "w", stdout);
#endif

    fprintf(file, "%d\n%d\n%d\n", 1, 4, 9);
    for (int s = 2; s <= 51; ++s) { // sqrt length
        printf("s=%d\n", s);
        const int middle = (s+1) / 2;
        const int middle_m1 = middle - 1;
        const int last_middle_m1 = s % 2 == 0 ? 1 : 2;
        Big b1, b2;
        b1.d.resize(s);
        vector<int> digits;
        digits.resize(middle);
        if (s > 2) {
            digits.front() = 1;
            digits.back() = -1;
        }

        bool end = false;
        while (true) {
            int last = last_middle_m1;
            for (int i = middle_m1; ; --i, last = 1) {
                if (digits[i] < last)
                    ++digits[i];
                else if (i != 0) {
                    digits[i] = 0;
                    continue;
                }
                else {
                    if (digits[i] != 2)
                        ++digits[i];
                    else
                        end = true;
                }
                break;
            }
            if (end)
                break;

            copy(digits.begin(), digits.end(), b1.d.begin());
            for (int i = s - 1; i >= middle; --i)
                b1.d[i] = b1.d[s-1-i];
            b2 = b1;
            b2 *= b1;
            b2.printIfPalindrome();
        }
    }







#ifndef ONLINE_JUDGE
    fclose(stdin);
    putchar('\n');
#endif
}


