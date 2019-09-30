N, M = map(int, input().split())
A = []
for _ in range(N):
    k_a = map(int, input().split())
    A.append(list(k_a)[:])

LIKE = [0 for _ in range(M + 1)]

for Ai in A:
    for a in Ai[1:]:
        LIKE[a] += 1

ans = 0
for x in LIKE:
    if x == N:
        ans += 1
print(ans)