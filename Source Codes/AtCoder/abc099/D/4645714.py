N,C = map(int, input().split())
cost = [list(map(int, input().split())) for _ in range(C)]
color = [list(map(lambda x:int(x)-1, input().split())) for _ in range(N)]

mod3 = {0:[], 1:[], 2:[]}
for i in range(N):
    for j in range(N):
        m = (i+j)%3
        mod3[m].append(color[i][j])
        
from collections import Counter
from itertools import combinations, permutations
cnts = [Counter(mod3[i]) for i in range(3)]
# print(cnts)
ans = float('inf')
for comb in combinations(range(C), 3):
    for p in permutations(comb):
        cond = 0
        for i in range(3):
            for col in cnts[i].keys():
                cond += cnts[i][col]*cost[col][p[i]]
        ans = min(ans, cond)
        #print(cond, p)
print(ans)