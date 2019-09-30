s = list(input())

n = len(s)

a = [0] * n

MOD = 998244353

for i in range(n):
    a[i] = ord(s[i]) - ord('a')

if max(a) == min(a):
    print(1)
    exit()
elif n == 3:
    def solver(m):
        x = m // 100
        y = ( m % 100 ) // 10
        z = m % 10
        if x != y:
            c = (3 - x - y) % 3
            temp = c * 110 + z
            if temp not in ans:
                ans.add(temp)
                solver(temp)
        if y != z:
            c = (3 - y - z) % 3
            temp = x * 100 + c * 11
            if temp not in ans:
                ans.add(temp)
                solver(temp)

    t = a[0] * 100 + a[1] * 10 + a[2]
    ans = set()
    ans.add(t)
    solver(t)
    print(len(ans))
    exit()
elif n == 2:
    print(2)
    exit()

dp = [[0,0,0] for _ in range(3)]

dp[0][0] = 1
dp[1][1] = 1
dp[2][2] = 1

for i in range(n-1):
    T = [[0,0,0] for _ in range(3)]
    T[0][0] = (dp[1][0] + dp[2][0]) % MOD
    T[0][1] = (dp[1][1] + dp[2][1]) % MOD
    T[0][2] = (dp[1][2] + dp[2][2]) % MOD
    T[1][0] = (dp[0][2] + dp[2][2]) % MOD
    T[1][1] = (dp[0][0] + dp[2][0]) % MOD
    T[1][2] = (dp[0][1] + dp[2][1]) % MOD
    T[2][0] = (dp[0][1] + dp[1][1]) % MOD
    T[2][1] = (dp[0][2] + dp[1][2]) % MOD
    T[2][2] = (dp[0][0] + dp[1][0]) % MOD
    dp, T = T, dp

m = sum(a) % 3

ans = 3 ** (n-1) - (dp[0][m] + dp[1][m] + dp[2][m])

check = 1
for i in range(n-1):
    if a[i] == a[i+1]:
        check = 0
        break

ans += check

#print(dp, 2 ** (n-1))

print(ans % MOD)