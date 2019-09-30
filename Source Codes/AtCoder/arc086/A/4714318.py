N, K = map(int, input().split())
A = [int(_) for _ in input().split()]
num = len(set(A))
cnt = [0]*(N+1)
ans = 0

for i in A:
    cnt[i] += 1

for i in range(N+1):
    if cnt[i] == 0:
        cnt[i] = N+1
        
cnt = sorted(cnt)
for i in range(max(0, num-K)):
    ans += cnt[i]

print(ans)