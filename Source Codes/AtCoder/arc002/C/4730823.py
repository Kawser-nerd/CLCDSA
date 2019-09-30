n = int(input())
C = list(input())
Lis = "ABXY"

def calc(L, R):
    dp = [0, 1]
    for i in range(1, n):
        if C[i-1] == L[0] and C[i] == L[1] and dp[i] != dp[i-1]:
            dp.append(dp[i])
        elif C[i-1] == R[0] and C[i] == R[1] and dp[i] != dp[i-1]:
            dp.append(dp[i])
        else:
            dp.append(dp[i] + 1)
    return dp[-1]
            
cou = n
for a in Lis:
    for b in Lis:
        for c in Lis:
            for d in Lis:
                if a == c and b == d:
                    continue
                L = a + b
                R = c + d
                re = calc(L, R)
                cou = min(re, cou)

print(cou)