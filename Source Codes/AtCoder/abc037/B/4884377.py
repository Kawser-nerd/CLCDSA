N, Q = map(int, input().split())
ans = [0 for i in range(N)]
for i in range(Q):
    L, R, T = map(int, input().split())
    for s in range(L, R+1):
        ans[s-1] = T
[print(i) for i in ans]