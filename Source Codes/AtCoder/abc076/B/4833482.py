N = int(input())
K = int(input())

best = 10**9
for i in range(2**N):
    v = 1
    for j in range(N):
        if (i >> j) & 1:
            v *= 2
        else:
            v += K
    best = min(best, v)
print(best)