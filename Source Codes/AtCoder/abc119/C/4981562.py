N, A, B, C = map(int, input().split())

bamboos = []
for _ in range(N):
    l = int(input())
    bamboos.append(l)
    
import copy

def dfs(i, bs):
    if i == len(bamboos):
        #print(bs)
        if not bs['A'] or not bs['B'] or not bs['C']:
            return []
        return [bs]
    ret = []
    tmp = copy.deepcopy(bs)
    tmp['A'].append(bamboos[i])
    ret.extend(dfs(i+1, tmp))
    tmp = copy.deepcopy(bs)
    tmp['B'].append(bamboos[i])
    ret.extend(dfs(i+1, tmp))
    tmp = copy.deepcopy(bs)
    tmp['C'].append(bamboos[i])
    ret.extend(dfs(i+1, tmp))
    tmp = copy.deepcopy(bs)
    tmp['D'].append(bamboos[i])
    ret.extend(dfs(i+1, tmp))
    
    return ret

ABC = {'A': A, 'B': B, 'C': C}
bs_comb = dfs(0, {'A':[],'B':[],'C':[],'D':[]})

import sys
ans = sys.maxsize
for bs in bs_comb:
    cost = 0
    for abc in ['A', 'B', 'C']:
        cost += (len(bs[abc]) - 1) * 10
        cost += abs(sum(bs[abc]) - ABC[abc])
    ans = min(ans, cost)
print(ans)