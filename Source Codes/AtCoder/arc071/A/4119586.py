from collections import Counter
N = int(input())
S = []
for _ in range(N):
    s = input()
    C = Counter(s)
    S.append(C)

dp = [float('inf')]*26
uni_a = ord('a')
for s in S:
    for i in range(26):
        dp[i] = min(dp[i], s[chr(uni_a+i)])

ans = ''

for i in range(26):
    ans += chr(uni_a+i)*dp[i]
print(ans)