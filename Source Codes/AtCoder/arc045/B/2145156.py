# -*- coding: utf-8 -*-
from bisect import bisect, bisect_left
def inpl(): return list(map(int, input().split()))

N, M = inpl()
R = [0]*(N+2)

Q = [inpl() for _ in range(M)]

for s, t in Q:
    R[s] += 1
    R[t+1] -= 1

c = 0
Pf = []
Pe = []
rec = False
f = -1
for i, r in enumerate(R):
    c += r
    if (c >= 2):
        if rec:
            pass
        else:
            rec = True
            f = i
    else:
        if rec:
            Pf.append(f)
            Pe.append(i-1)
            rec = False
        else:
            pass
if rec:
    Pf.append(f)
    Pe.append(N)

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