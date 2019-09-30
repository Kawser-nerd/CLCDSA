MOD = 998244353


def get_inv(n):
    inv = [0] * (n + 1)
    inv[1] = 1

    for i in range(2, n + 1):
        inv[i] = (-(MOD // i) * inv[MOD % i]) % MOD

    return inv


def get_cmb(n):
    inv = get_inv(n)
    cmb = [0] * (n + 1)
    cmb[0] = 1

    for i in range(1, n + 1):
        cmb[i] = (cmb[i - 1] * (n - i + 1) * inv[i]) % MOD

    return cmb


def solve(n, a, b, k):
    ans = 0
    cmb = get_cmb(n)
    for a_num in range(n + 1):
        b_num = (k - a * a_num) // b
        if (a * a_num + b * b_num == k) and (0 <= b_num <= n):
            ans += (cmb[a_num] * cmb[b_num]) % MOD
            ans %= MOD
    return ans


def main():
    n, a, b, k = list(map(int, input().split()))
    ans = solve(n, a, b, k)
    print(ans)


main()