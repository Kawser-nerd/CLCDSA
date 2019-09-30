N, K, Q = map(int, input().split())
As = list(map(int, input().split()))

ans = 10 ** 9
for Y in sorted(As)[:N - Q - K + 2]:
    cands = []
    cs = []
    for A in As + [0]: # ???????
        if A < Y:
            if len(cs) >= K:
                cands += sorted(cs)[:len(cs) - K + 1]
            cs = []
        else:
            cs += [A]

    if len(cands) < Q: continue
    X = sorted(cands)[Q - 1]

    ans = min(ans, X - Y)

print(ans)