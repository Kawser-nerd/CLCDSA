n = int(input())


def prime(k):
    p = [True] * (k+1)
    p[0] = False
    p[1] = False
    for i in range(2, k+1):
        if p[i]:
            for j in range(i*2, k+1, i):
                p[j] = False
    return [i for i in range(k + 1) if p[i]]


def mod5(px):
    return [p for p in px if p % 5 == 1]


px = prime(2000)
qx = mod5(px)

print(' '.join(map(str, qx[0:n])))