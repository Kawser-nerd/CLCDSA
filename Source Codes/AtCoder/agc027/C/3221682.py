from collections import defaultdict
import sys
sys.setrecursionlimit(10**8)

N,M = map(int, input().split())
s = list(input())

'''
A
1 ~ N -> mod0
N+1 ~ 2N -> mod1

B
1 ~ N -> mod2
N+1 ~ 2N -> mod3
'''

lines = [[] for i in range(2*N)]
for _ in range(M):
    a,b = map(int, input().split())
    a-=1
    b-=1
    sa, sb = s[a], s[b]
    if sa == sb:
        lines[a].append(b+N)
        lines[b].append(a+N)
    else:
        lines[a+N].append(b)
        lines[b+N].append(a)

ed = [0]*(2*N)

def dfs(s):
    global ed
    ed[s] = 1
    for t in lines[s]:
        if ed[t] == 1: #??????
            print('Yes')
            sys.exit()
        elif ed[t] == 0:
            dfs(t)
    ed[s] = 2

for s in range(N):
    if ed[s] == 0:
        dfs(s)

print('No')