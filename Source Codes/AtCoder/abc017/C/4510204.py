N, M = map(int, input().split())
ans = [0]*(M+1)
maxscore = 0
for i in range(N):
  l, r, s = map(int, input().split())
  ans[l-1] += s
  ans[r] -= s
  maxscore += s
for j in range(1, M+1):
  ans[j] += ans[j-1]
print(maxscore - min(ans[:-1]))