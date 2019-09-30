import sys
sys.setrecursionlimit(10**9)

def dfs(iNow):
    if len(adjL[iNow]) == 0:
        return 0
    Bs = [dfs(i2) for i2 in adjL[iNow]]
    Bs.sort()
    ans = max([B-i for i, B in enumerate(Bs)])
    return ans + len(Bs)

N = int(input())
adjL = [[] for v in range(N)]
for i in range(1, N):
    A = int(input())
    adjL[A-1].append(i)

print(dfs(0))