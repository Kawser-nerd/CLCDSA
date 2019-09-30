from collections import Counter
mod = 10**9+7
def check(s):
    ban = ["AGC", "ACG", "GAC", "AGGC", "ATGC", "AGTC"]
    for b in ban:
        if b in s:
            return False
    return True

n = int(input())
dp = [Counter() for i in range(n+1)]
dp[0]["RAN"] = 1

for i in range(n):
    for key, value in dp[i].items():
        for c in "ACTG":
            if check(key+c):
                dp[i+1][key[1:]+c]+=value % mod

print (sum(dp[n].values())%mod)