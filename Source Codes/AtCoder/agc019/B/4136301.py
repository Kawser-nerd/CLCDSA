S = input()
N = len(S)
DP = [0]*26
ans = 0
for st in S:
  DP[ord(st) - ord('a')] += 1
for i in range(26):
  ans += DP[i] * (N - DP[i])
print(ans//2 + 1)