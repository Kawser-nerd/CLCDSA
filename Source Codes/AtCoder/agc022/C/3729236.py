def inpl(): return [int(i) for i in input().split()]
from collections import defaultdict
import sys
def edge(S):
    e = defaultdict(lambda: set())
    for i in range(N+1):
        for j in S:
            e[i].add(i%j)
        e[i] = e[i] | {i}
    return e
def path(edge):
    p = defaultdict(lambda: set())
    for st in range(N+1):
        Q, p[st], new = [edge[st]]*3
        while Q:
            for j in Q:
                new = new | edge[j]
            Q = new - p[st]
            p[st] = p[st] | new
    return p

K = int(input())
A = inpl()
B = inpl()
for i in range(K):
    if A[i] < B[i]:
        print(-1)
        sys.exit()
if A == B:
    print(0)
    sys.exit()
N = max(A) 
T = []
for l in range(N,-1,-1):
    S = T + list(range(1,1+l))
    Pa = path(edge(S))
    for i in range(K):
        if B[i] not in Pa[A[i]]:
            break
    else:
        continue
    T.append(l+1)
if not T:
    print(2)
    sys.exit()
if N+1 in T:
    print(-1)
    sys.exit()
print(sum([2**i for i in T]))