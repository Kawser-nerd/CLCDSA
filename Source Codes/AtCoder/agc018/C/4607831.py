import numpy as np
from heapq import heappush, heappop


x, y, z = map(int, input().split())
n = x + y + z

a = np.zeros((n, ), dtype=np.int64)
b = np.zeros((n, ), dtype=np.int64)
c = np.zeros((n, ), dtype=np.int64)

for i in range(n):
    a[i], b[i], c[i] = map(int, input().split())

sub_ab = b-a

idx_arg = np.argsort(sub_ab)

pq_left = []
pq_right = []

mem = 0

cls = np.zeros((n, ), dtype=np.int64)


for i in range(x):
    mem += a[idx_arg[i]]
    heappush(pq_left, (a[idx_arg[i]]-c[idx_arg[i]], idx_arg[i]))
    cls[idx_arg[i]] = 1

for i in range(x, n):
    mem += c[idx_arg[i]]
    cls[idx_arg[i]] = 3
    heappush(pq_right, (c[idx_arg[i]]-b[idx_arg[i]], idx_arg[i]))
    if(len(pq_right) > z):
        _, idx = heappop(pq_right)
        mem -= c[idx]
        mem += b[idx]
        cls[idx] = 2

ans = mem


for i in range(x, x+z):
    if cls[idx_arg[i]] == 2:
        mem -= b[idx_arg[i]]
        while True:
            _, idx = heappop(pq_right)
            if cls[idx] == 3:
                mem -= c[idx]
                mem += b[idx]
                cls[idx] = 2
                break
    elif cls[idx_arg[i]] == 3:
        mem -= c[idx_arg[i]]
    cls[idx_arg[i]] = 1
    mem += a[idx_arg[i]]
    heappush(pq_left, (a[idx_arg[i]]-c[idx_arg[i]], idx_arg[i]))
    _, idx = heappop(pq_left)
    mem -= a[idx]
    mem += c[idx]
    cls[idx] = 0
    ans = max(ans, mem)

print(ans)