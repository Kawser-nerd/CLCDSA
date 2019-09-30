N = int(input())
dp = [0]*N
for i in range(N):
  dp[int(input())-1] = i
ans = 0
cc = 0
for i in range(N-1):
  if dp[i] < dp[i+1]:
    cc += 1
  else:
    ans = max(cc, ans)
    cc = 0
ans = max(cc, ans)
print(N-ans-1)