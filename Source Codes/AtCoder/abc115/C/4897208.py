N, K = map(int, input().split())
h = []
for i in range(N):
  h.append(int(input()))
h2 = sorted(h)
ans = 10**9
for i in range(N-K+1):
  if h2[i+K-1] - h2[i] < ans:
    ans = h2[i+K-1] - h2[i]
print(ans)