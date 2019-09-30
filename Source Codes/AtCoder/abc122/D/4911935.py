MOD = 10**9 + 7
memo = {}

def ok(last4):
    if "AGC" in last4:
        return False
    for i in range(3):
        s = list(last4)
        s[i], s[i+1] = s[i+1], s[i]
        if "AGC" in "".join(s):
            return False
    return True

def dfs(d, last3):
    if d < 0:
        return 1
    if not (d, last3) in memo:
        res = 0
        for c in "ACGT":
            last4 = last3 + c
            if ok(last4):
                res = (res + dfs(d-1, last4[-3:])) % MOD
        memo[d, last3] = res
    return memo[d, last3]

def solve(n):
    return dfs(n-1, "###")

n = int(input())
print(solve(n))