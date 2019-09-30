from itertools import product

K, N = map(int, input().split())
V, W = [None] * N, [None] * N
for i in range(N):
    V[i], W[i] = input().split()

for ptn in product(range(1, 4), repeat=K):
    s = [None] * K
    for i in range(N):
        v = list(map(int, V[i]))
        w = W[i]

        if sum([ptn[vi - 1] for vi in v]) != len(w):
            break

        for vi in v:
            l = ptn[vi - 1]
            s[vi - 1] = w[:l]
            w = w[l:]

    if sum([1 for si in s if si is None]) != 0:
        continue

    flag = True
    for i in range(N):
        v = list(map(int, V[i]))
        w = W[i]

        for vi in v:
            l = ptn[vi - 1]
            if s[vi - 1] != w[:l]:
                flag = False
                break
            w = w[l:]
        if not flag:
            break
    
    if flag:
        for si in s:
            print(si)
        break