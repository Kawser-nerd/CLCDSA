from time import time
start = time()
N, M, K = map(int, input().split())
P = [list(map(int, input().split())) for i in range(M)]

from random import seed, randint
seed()

def check(r, rN=[(1<<(i+1)%N) | (1<<i) for i in range(N)], rK=range(K)):
    for _ in r:
        *R, = rN
        for i in rK:
            a = randint(0, N-1)
            b = randint(0, N-2)
            b += a <= b
            R[a], R[b] = R[b], R[a]
        for a, b in P:
            if R[a]&R[b]:
                yield 0
                break
        else:
            yield 1

A = 100000
succ = sum(check(range(A)))

T = 10000
rT = range(T)
border = start + 9.5
while time() < border:
    succ += sum(check(rT))
    A += T
U = 500
rU = range(U)
border = start + 9.9
while time() < border:
    succ += sum(check(rU))
    A += U
print("%.10f" % (succ / float(A)))