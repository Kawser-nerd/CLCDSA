def inpl(): return [int(i) for i in input().split()]
from collections import defaultdict
import sys
Chi = defaultdict(lambda: [])
F = defaultdict(lambda: [])
N = int(input())
Par = [0] + [int(i)-1 for i in input().split()]
Dis = [-1]*N
X = inpl()
Col = [()]*N
for i in range(N):
    Chi[Par[i]].append(i)
Q = [0]
ctr = 0
while ctr < N:
    st = Q.pop()
    if not Chi[st]:
        continue
    for j in Chi[st]:
        Dis[j] = Dis[st] + 1
        ctr += 1
        Q.append(j)
Chi[0].remove(0)
mD = max(Dis)
for i in range(N):
    F[Dis[i]].append(i)
for d in range(mD, -1, -1):
    for i in F[d]:
        if not Chi[i]:
            Col[i] = (0,X[i])
            continue
        Su = 0
        H = defaultdict(lambda: 0)
        H[0] = 0
        for j in Chi[i]:
            a, b = Col[j]
            Su += a+b
            G = defaultdict(lambda: 0)
            for k in H.keys():
                if a + k <= X[i]:
                    G[a+k] = 1
                if b + k <= X[i]:
                    G[b+k] = 1
            H = G.copy()
            if not H:
                break
        else:
            Col[i] = (Su-max(H), X[i])
            continue
        break
    else:
        continue
    break
else:
    print('POSSIBLE')
    sys.exit()
print('IMPOSSIBLE')