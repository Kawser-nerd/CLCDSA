N, M = map(int, input().split())
S = []
C = []

for i in range(N):
    a, b = map(int, input().split())
    S.append((a, b))

for i in range(M):
    c, d = map(int, input().split())
    C.append((c, d))

for si in S:
    ans = -1
    min_ = 10 ** 10
    for i, ci in enumerate(C):
        ds = abs(ci[0] - si[0]) + abs(ci[1] - si[1])
        if ds < min_:
            min_ = ds
            ans = i
    print(ans + 1)