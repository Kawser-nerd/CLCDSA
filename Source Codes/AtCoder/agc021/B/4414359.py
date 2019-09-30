from math import pi, atan2

def andrange(a, b):
    if a == (0, 0) or b == (0, 0): return (0, 0)
    if a == (0, 1): return b
    if b == (0, 1): return a
    if a[0] > b[0]: a, b = b, a
    if b[1] < a[1]: return b
    if b[0] < a[1]: return (b[0], a[1])
    if b[1] < a[0] + 1: return (0, 0)
    if b[1] < a[1] + 1: return (a[0], b[1] - 1)
    return a

def calcrange(P, Q):
    c = atan2(P[1]-Q[1], P[0]-Q[0]) / (2*pi)
    if c > 0: return (c, c+0.5)
    else: return (c+1, c+1.5)

N = int(input())
X = []
for _ in range(N):
    x, y = map(int, input().split())
    X.append((x, y))

A = [(0, 1) for _ in range(N)]

for i in range(N):
    for j in range(N):
        if i != j:
            A[i] = andrange(A[i], calcrange(X[i], X[j]))

for a in A:
    print("{:.15f}".format(a[1] - a[0]))