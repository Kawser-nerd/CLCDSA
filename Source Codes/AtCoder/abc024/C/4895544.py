n, d, k = map(int, input().split())
LR = [tuple(int(x) for x in input().split()) for _ in range(d)]
ST = [list(map(int, input().split())) for _ in range(k)]

ans = [0] * k

for i, [L, R] in enumerate(LR):
    for j, [S, T] in enumerate(ST):
        if S < T:
            if L <= S < R:
                ST[j][0] = min(T, R)
                if ST[j][0] == T:
                    ans[j] = i + 1
        elif S > T:
            if L < S <= R:
                ST[j][0] = max(T, L)
                if ST[j][0] == T:
                    ans[j] = i + 1
    #print(ST)

for x in ans:
    print(x)