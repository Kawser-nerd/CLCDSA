N, M = map(int, input().split())
A = [[0, 0] for i in range(M)]

for i in range(M):
    A[i][0], A[i][1] = map(int, input().split())

A.sort(key=lambda x:(x[1], x[0]))

ans = 0
x = 0
for a in A:
    if x < a[0]:
        x = a[1] - 1
        ans += 1
print(ans)