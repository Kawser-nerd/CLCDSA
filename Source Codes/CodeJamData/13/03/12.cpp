#include <stdio.h>
#include <string.h>

struct BigInt {
    int len;
    int dig[210];

    BigInt() {
        len = 1;
        memset(dig, 0, sizeof(dig));
    }
    BigInt(int x) {
        len = 1;
        memset(dig, 0, sizeof(dig));
        dig[0] = x;
    }

    BigInt& operator++() {
        dig[0] ++;
        for (int i=0; dig[i] >= 10; i++) {
            dig[i] -= 10;
            if (i < len-1) {
                dig[i+1] ++;
            } else {
                dig[i+1] = 1;
                len++;
            }
        }
        return *this;
    }

    BigInt operator*(const BigInt &b) const {
        BigInt ret;
        for (int i=0; i<len; i++) {
            for (int j=0; j<b.len; j++) {
                ret.dig[i+j] += dig[i] * b.dig[j];
                ret.dig[i+j+1] += ret.dig[i+j] / 10;
                ret.dig[i+j] %= 10;
            }
        }
        ret.len = len + b.len - 1;
        if (ret.dig[ret.len]) ret.len++;
        return ret;
    }

    bool operator<(const BigInt &b) const {
        if (len != b.len) return len < b.len;
        for (int i=len-1; i>=0; i--) {
            if (dig[i] != b.dig[i]) return dig[i] < b.dig[i];
        }
        return false;
    }

    bool operator<=(const BigInt &b) const {
        if (len != b.len) return len < b.len;
        for (int i=len-1; i>=0; i--) {
            if (dig[i] != b.dig[i]) return dig[i] < b.dig[i];
        }
        return true;
    }

    BigInt operator/(int b) const {
        BigInt ret;
        ret.len = len;
        int cur = 0;
        for (int i=len-1; i>=0; i--) {
            ret.dig[i] = (cur * 10 + dig[i]) / b;
            cur = (cur * 10 + dig[i]) % b;
        }
        while (ret.len>1 && !ret.dig[ret.len-1]) ret.len--;
        return ret;
    }

    BigInt reverse() const {
        BigInt ret;
        ret.len = len;
        for (int i=0; i<len; i++) ret.dig[len-1-i] = dig[i];
        return ret;
    }

    BigInt palindrome1() const {
        BigInt ret;
        ret.len = 2*len-1;
        for (int i=0; i<len; i++) ret.dig[i] = dig[i];
        for (int i=0; i<len; i++) ret.dig[ret.len-1-i] = dig[i];
        return ret;        
    }

    BigInt palindrome2() const {
        BigInt ret;
        ret.len = 2*len;
        for (int i=0; i<len; i++) ret.dig[i] = dig[i];
        for (int i=0; i<len; i++) ret.dig[ret.len-1-i] = dig[i];
        return ret;        
    }

    bool isPalindrome() const {
        for (int i=0; i<len/2; i++) {
            if (dig[i] != dig[len-1-i]) return false;
        }
        return true;        
    }

    BigInt last(int n) const {
        BigInt ret;
        ret.len = n;
        for (int i=0; i<n; i++) ret.dig[i] = dig[i];        
        return ret;
    }

    BigInt extend(int n) const {
        BigInt ret;
        ret.len = len+1;
        for (int i=0; i<len; i++) ret.dig[i] = dig[i];        
        ret.dig[len] = n;
        return ret;
    }

    BigInt sqrt() const {
        BigInt ret;
        ret.len = (len+1)/2;
        for (int i=ret.len-1; i>=0; i--) {
            for (ret.dig[i] = 1; ret.dig[i] < 10 && ret * ret < *this; ret.dig[i]++);
            ret.dig[i]--;
            if (i == ret.len-1 && i>=1 && ret.dig[i] == 0) ret.len--;
        }
        return ret;
    }

    static BigInt scan() {
        char inp[110];
        scanf("%s", inp);

        BigInt ret;
        ret.len = strlen(inp);

        for (int i=0; i<ret.len; i++) {
            ret.dig[ret.len-1-i] = inp[i] - '0';
        }
        return ret;
    }

    void print() const {
        for (int i=len-1; i>=0; i--) {
            printf("%d", dig[i]);
        }
        puts("");
    }
};
int dp[10][30], dpo[10][30];
int init() {
    for (int i=0; i<30; i++) dp[0][i] = 1, dpo[0][i] = 1;
    for (int i=1; i<10; i++) {
        dp[i][0] = 1, dpo[i][0] = i<1 ? 1 : i<4 ? 2 : i<9 ? 3 : 4;
        for (int k=1; k<30; k++) {
            for (int j=0; 2*j*j<=i; j++) {
                dp[i][k] += dp[i-2*j*j][k-1];
                dpo[i][k] += dpo[i-2*j*j][k-1];
            }
        }
    }
}
int calc(const BigInt& n) {
    int ans = (n.len > 1 ? dpo[9][n.len/2-1] - 1 : 0) + dp[9][(n.len-1)/2];
                //printf("%d %d\n", (n.len > 1 ? dpo[9][n.len/2-1] - 1 : 0), dp[9][(n.len-1)/2]);
    int ava = 9;
    if (n.len%2 == 0) {
        for (int i=n.len-1; i >= n.len/2; i--) {
            for (int j = (i==n.len-1) ? 1 : 0; j < n.dig[i]; j++) {
                if (ava - 2*j*j >= 0) {   
                    ans += dp[ava-2*j*j][i-n.len/2];
                }
            }
            ava -= 2 * n.dig[i] * n.dig[i];
            if (ava < 0) break;
        }
    } else {
        for (int i=n.len-1; i >= (n.len)/2; i--) {
            if (i > n.len/2) {
                for (int j = (i==n.len-1) ? 1 : 0; j < n.dig[i]; j++) {
                    if (ava - 2*j*j >= 0) {   
                        ans += dpo[ava-2*j*j][i-(n.len+1)/2];
                    }
                }
                ava -= 2*n.dig[i] * n.dig[i];
                if (ava < 0) break;
            } else {
                for (int j = (i==n.len-1) ? 1 : 0; j < n.dig[i]; j++) {
                    if (ava - j*j >= 0) {   
                        ans += 1;
                    }
                }
                ava -= n.dig[i] * n.dig[i];
            }
        }
    }
    if (ava >= 0 && (n.len > 1 || n.dig[0] > 0)) {
        bool isPal = true;
        for (int i = n.len/2-1; i>=0; i--) {
            if (n.dig[i] != n.dig[n.len-1-i]) {
                isPal = n.dig[i] > n.dig[n.len-1-i];
                break;
            }
        }
        if (isPal) ans ++;
    }
    //n.print(); //printf("ret %d\n", ans);
    return ans;
}
int main() {
    init();
    int casN;
    scanf("%d", &casN);
    for (int i=0; i<casN; i++) {
        BigInt low = BigInt::scan(), high = BigInt::scan();
        ++high;
        printf("Case #%d: %d\n", i+1, calc(high.sqrt()) - calc(low.sqrt()));
    }
    return 0;
}
