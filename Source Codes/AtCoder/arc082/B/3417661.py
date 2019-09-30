N = int(input())
p = list(map(int, input().split()))
ans = 0
for i in range(N - 1):
    if i + 1 == p[i]:
        p[i + 1], p[i] = p[i], p[i + 1]
        ans += 1
print(ans if p[N - 1] != N else ans + 1)