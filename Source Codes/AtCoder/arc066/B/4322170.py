N = int(input())
binN = format(N, "b").zfill(60)
mod = 7 + 10 ** 9

DP = [[0, 0, 0] for _ in range(60)]
if binN[0] == "0":
    DP[0] = [1, 0, 0]
else:
    DP[0] = [1, 1, 0]

for i in range(1, 60):   
    if binN[i] == "0":
        DP[i][0] = (DP[i-1][0] + DP[i-1][1]) % mod
        DP[i][1] = DP[i-1][1]
        DP[i][2] = (DP[i-1][2] * 3 + DP[i-1][1]) % mod
    else:
        DP[i][0] = DP[i-1][0]
        DP[i][1] = (DP[i-1][0] + DP[i-1][1]) % mod
        DP[i][2] = (DP[i-1][2] * 3 + DP[i-1][1] * 2) % mod
print(sum(DP[-1]) % mod)