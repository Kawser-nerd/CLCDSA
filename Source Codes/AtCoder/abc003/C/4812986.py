N, K = map(int, input().split())
R = sorted(map(int, input().split()))[N - K :N]
ans = 0
for i in R:
  ans = (ans + i)/2
print(ans)