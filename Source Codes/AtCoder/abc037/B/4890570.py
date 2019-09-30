N, Q = map(int, input().split())
a = [0] * (N + 1)
for i in range(Q):
    L, R, T = map(int, input().split())
    for j in range(L, R + 1):
        a[j] = T

for i in range(1, N + 1):
    print(a[i])