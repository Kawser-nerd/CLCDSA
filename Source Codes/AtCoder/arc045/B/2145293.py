# -*- coding: utf-8 -*-
from bisect import bisect
def inpl(): return list(map(int, input().split()))

N, M = inpl()
R = [0]*(N+2)

Q = [inpl() for _ in range(M)]

for s, t in Q:
    R[s] += 1
    R[t+1] -= 1

R[-1] = - 2 * M
c, f = 0, -1
Pf, Pe = [], []
rec = False

for i, r in enumerate(R):
    c += r
    if (c >= 2) == rec:
        pass
    elif rec:
        Pf.append(f)
        Pe.append(i-1)
        rec = False 
    else:
        f = i
        rec = True

ANS = []
for i, (s, t) in enumerate(Q, start=1):
    j = bisect(Pf, s)
    if j:
        e = Pe[j-1]
        if t <= e:
            ANS.append(i)
    else:
        pass
    
print(len(ANS))
if len(ANS):
    print(*ANS, sep="\n")