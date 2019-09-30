import sys

N = int(input())
scores = list(map(int, sys.stdin))
perfect = sum(scores)

dp = [1] + [0]*perfect

for s in scores:
    for i in range(perfect-s, -1, -1):
        dp[i+s] |= dp[i]

for s in range(perfect, 0, -1):
    if dp[s] and s % 10:
        print(s)
        break
else:
    print(0)