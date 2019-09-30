N, K = map(int, input().split())
a = [int(_) for _ in input().split()]
Csum = [0]*(N+1)
tmp = 0
cnt = 0
for i in a:
    cnt += 1
    tmp += i
    Csum[cnt] = tmp

ans = 0
for i in range(0, N-K+1):
    ans += Csum[i+K] - Csum[i]

print(ans)