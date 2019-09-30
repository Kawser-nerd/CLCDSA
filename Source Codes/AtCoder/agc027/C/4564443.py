import sys
sys.setrecursionlimit(200000)
n, m = map(int, input().split())
s = input()
out = [set() for _ in range(n)]
count = [[0, 0] for _ in range(n)]
def f(c):
    if c == 'A': return 0
    else: return 1
for _ in range(m):
    a, b = map(int, input().split())
    if a == b:
        count[a-1][f(s[a-1])] += 1
    elif b-1 not in out[a-1]:
        count[a-1][f(s[b-1])] += 1
        count[b-1][f(s[a-1])] += 1
    out[a-1].add(b-1)
    out[b-1].add(a-1)
elim = set()
def eliminate(x):
    elim.add(x)
    c = f(s[x])
    for node in out[x]:
        if node not in elim:
            count[node][c] -= 1
            if count[node][0] * count[node][1] == 0:
                eliminate(node)
for i in range(n):
    if i not in elim and count[i][0] * count[i][1] == 0:
        eliminate(i)
if len(elim) < n: print('Yes')
else: print('No')