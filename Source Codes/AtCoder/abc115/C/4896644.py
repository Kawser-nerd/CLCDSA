N,K = map(int,input().split())
h = [int(input()) for _ in range(N)]

h = sorted(h)
hK = h[0:K]
ans = hK[K-1]-h[0]
for i in range(N-K+1):
    ans = min(ans,h[i+K-1]-h[i])

print(ans)