import numpy as np
from collections import defaultdict

def cross(a, b):
    return a[0]*b[1]-a[1]*b[0]

n = int(input())
H = [np.array([int(j) for j in input().split()]) for i in range(n)]

convex = [min(H, key=lambda x:x[1])]

for i in range(n):
    a = H[0] if (H[0] != convex[-1]).any() else H[-1]
    for b in H:
        ac = a-convex[-1]
        bc = b-convex[-1]
        cross_ = cross(ac, bc)
        if cross_ < 0 or (cross_ == 0 and np.linalg.norm(ac) < np.linalg.norm(bc)):
            a = b
    if (a == convex[0]).all():
        break
    convex.append(a)

ans = defaultdict(float)

for c, a, b in zip([convex[-1]]+convex[:-1], convex, convex[1:] + [convex[0]]):
    ca = c-a
    ba = b-a
    i = np.inner(ca, ba)
    n = np.linalg.norm(ca) * np.linalg.norm(ba)
    ans[tuple(a)] = (np.pi - np.arccos(np.clip(i/n, -1, 1))) / (2*np.pi)

for i in H:
    print(ans[tuple(i)])