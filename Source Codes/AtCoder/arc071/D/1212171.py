import sys

mod = 10**9 + 7

def solve():
    n = int(input())

    if n == 1:
        print(1)
        return

    dp = [0] * (n + 1)
    dp[1] = n % mod
    dp[2] = n**2 % mod

    acc = [0] * (n + 1)
    acc[1] = dp[1] % mod
    acc[2] = (dp[1] + dp[2]) % mod

    for k in range(3, n + 1):
        dp[k] = (dp[k - 1] + (n - 1)**2 + acc[k - 3] + n - k + 2) % mod
        acc[k] = (acc[k - 1] + dp[k]) % mod

    ans = dp[n]
    print(ans)

def debug(x, table):
    for name, val in table.items():
        if x is val:
            print('DEBUG:{} -> {}'.format(name, val), file=sys.stderr)
            return None

if __name__ == '__main__':
    solve()