from collections import Counter

MOD = 10**9+7
N = int(input())

dp = [Counter() for i in range(N+1)]
dp[0]["TTT"] = 1


def ok(last4):
    bad = ["AGC", "ACG", "GAC", "AGGC", "ATGC", "AGTC"]
    for b in bad:
        if b in last4:
            return False
    return True

for i in range(N):
    for key, value in dp[i].items():
        for c in "AGCT":
            if ok(key+c):
                dp[i+1][key[1:]+c] += value % MOD

print(sum(dp[N].values()) % MOD)