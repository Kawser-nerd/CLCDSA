#16:01
N, T = map(int, input().split())
t = list(map(int, input().split()))
ans = T
for i in range(1,N):
    ans += min(t[i] - t[i-1], T)
print(ans)