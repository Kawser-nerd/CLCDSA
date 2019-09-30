S = input()

dp = [[None] * 4 for _ in range(len(S))]
dp.append([0, 0, 0, 1])
next_str = ["A", "B", "C"]
MOD = 10**9 + 7

for i, s in enumerate(reversed(S)):
    i = len(S) - i - 1
    for j in range(4):
        if j == 3:
            if s == "?":
                dp[i][j] = (3 * dp[i + 1][j]) % MOD
            else:
                dp[i][j] = dp[i + 1][j] % MOD
        else:
            if s == "?":
                m_1 = 3
                m_2 = 1
            else:
                m_1 = 1
                if s == next_str[j]:
                    m_2 = 1
                else:
                    m_2 = 0
            dp[i][j] = (m_1 * dp[i + 1][j] + m_2 * dp[i + 1][j + 1]) % MOD


print(dp[0][0])