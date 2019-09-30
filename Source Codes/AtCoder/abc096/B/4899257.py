A, B, C = map(int, input().split())
K = int(input())

m = max([A, B, C])
ans = A + B + C - m
for i in range(K):
    m *= 2
ans += m

print(ans)