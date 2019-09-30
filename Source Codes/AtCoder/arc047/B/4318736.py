import numpy as np
from itertools import product
n = int(input())

#x, y = zip(*(tuple(map(int, input().split())) for _ in range(n)))???
X, Y = np.array([np.array(list(map(int, input().split()))) for _ in range(n)]).T
U, V = np.array([np.array([i-j, i+j]) for i, j in zip(X, Y)]).T
d = max(max(U)-min(U), max(V)-min(V))
for i, j in product((max(U)-d//2, d//2+min(U)), (max(V)-d//2, d//2+min(V))):
    px, py = (i+j)//2, (-i+j)//2
    s = set()
    for x, y in zip(X, Y):
        s.add(abs(px-x)+abs(py-y))
        if len(s) > 1:
            break
    else:
        print(px, py)
        break