n = input()
keta = len(n)

dp = [[[-1]*(keta+1) for i in range(2)] for j in range(keta+1)]

def rec(k=0, tight=1, sum=0):
    if k==keta:
        return sum
    if dp[k][tight][sum] != -1:
        return dp[k][tight][sum]
    max_j = int(n[k]) if tight else 9
    res = 0
    for j in range(max_j+1):
        res += rec(k+1, tight and j == max_j, sum + int(j==1))
    dp[k][tight][sum] = res
    return dp[k][tight][sum]

print(rec())