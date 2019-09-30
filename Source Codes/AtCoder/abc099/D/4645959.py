from collections import Counter
from itertools import permutations
N,C = map(int, input().split())
cost = [list(map(int, input().split())) for _ in range(C)]
color = [list(map(lambda x:int(x)-1, input().split())) for _ in range(N)]

# 3 groups
mod3 = {0:[], 1:[], 2:[]}
for i in range(N):
    for j in range(N):
        m = (i+j)%3
        mod3[m].append(color[i][j])

cnts = [Counter(mod3[i]) for i in range(3)]
cost_mod = [[-1]*C for _ in range(3)]
for i in range(3):
    for to_ in range(C):
        cond = 0
        for from_ in cnts[i].keys():
            cond += cnts[i][from_]*cost[from_][to_]
        cost_mod[i][to_] = cond

ans = float('inf')
for p in permutations(range(C), 3):
    cond = 0
    for i in range(3):
        cond += cost_mod[i][p[i]]
    ans = min(ans, cond)
    #print(cond, p)
print(ans)