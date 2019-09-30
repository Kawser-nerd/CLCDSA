N,M = map(int, input().split())
KA = []
a = []
ans = 0

for i in range(N):
    KA = list(map(int, input().split()))
    A = KA[1:]
    a += A
for j in range(1,M+1):
    if a.count(j) == N:
        ans += 1
print(ans)