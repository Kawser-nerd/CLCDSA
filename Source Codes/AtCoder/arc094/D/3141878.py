def solve(s):
    if all(a == b for a, b in zip(s, s[1:])):
        return 1
    if len(s) == 2:
        return 2
    elif len(s) == 3:
        if s[0] == s[1] or s[1] == s[2]:
            return 6
        elif s[0] == s[2]:
            return 7
        else:
            return 3
    # dp[has succession=0][mod 3][last char], dp[has succession=1][mod 3]
    dp = [[[0] * 3 for _ in range(3)], [0] * 3]
    dp[0][0][0] = 1
    dp[0][1][1] = 1
    dp[0][2][2] = 1
    MOD = 998244353
    for _ in range(len(s) - 1):
        ndp = [[[0] * 3 for _ in range(3)], [0] * 3]
        dp0, dp1 = dp
        ndp0, ndp1 = ndp
        sdp1 = sum(dp1)
        ndp0[0][0] = (dp0[0][1] + dp0[0][2]) % MOD
        ndp0[1][0] = (dp0[1][1] + dp0[1][2]) % MOD
        ndp0[2][0] = (dp0[2][1] + dp0[2][2]) % MOD
        ndp0[0][1] = (dp0[2][0] + dp0[2][2]) % MOD
        ndp0[1][1] = (dp0[0][0] + dp0[0][2]) % MOD
        ndp0[2][1] = (dp0[1][0] + dp0[1][2]) % MOD
        ndp0[0][2] = (dp0[1][0] + dp0[1][1]) % MOD
        ndp0[1][2] = (dp0[2][0] + dp0[2][1]) % MOD
        ndp0[2][2] = (dp0[0][0] + dp0[0][1]) % MOD
        ndp1[0] = (dp0[0][0] + dp0[1][2] + dp0[2][1] + sdp1) % MOD
        ndp1[1] = (dp0[1][0] + dp0[2][2] + dp0[0][1] + sdp1) % MOD
        ndp1[2] = (dp0[2][0] + dp0[0][2] + dp0[1][1] + sdp1) % MOD
        dp = ndp
    return (dp[1][sum(map(ord, s)) % 3] + all(a != b for a, b in zip(s, s[1:]))) % MOD


s = input()
print(solve(s))