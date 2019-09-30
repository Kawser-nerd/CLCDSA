from heapq import *
N, K, Q = map(int, input().split())
a = list(map(int, input().split()))
b = [None]*(N+2)
x = []

def merge(q1, q2):
    if q1 < q2:
        q1, q2 = q2, q1
    s = q1[0] + q2[0]
    while q2[1]:
        add(q1, heappop(q2[1]))
    q1[0] = s
    return q1

def add(q, v):
    q[0] += 1
    w = push(q[1], K-1, v)
    if w:
        push(x, Q, -w)

def push(q, m, v):
    if len(q) < m:
        heappush(q, v)
        return
    return heappushpop(q, v)

r = 10**9
for i in sorted(range(1, N+1), key=lambda x: -a[x-1]):
    if b[i-1] and b[i+1]:
        s, t = b[i-1][0], b[i+1][0]
        b[i-s] = b[i+t] = merge(b[i-1], b[i+1])
        add(b[i-s], a[i-1])
        b[i] = 1
    elif b[i-1]:
        add(b[i-1], a[i-1])
        b[i] = b[i-1]
    elif b[i+1]:
        add(b[i+1], a[i-1])
        b[i] = b[i+1]
    else:
        b[i] = [0,[]]
        add(b[i], a[i-1])
    if len(x) == Q:
        r = min(r, -x[0]-a[i-1])
print(r)