import sys

sys.setrecursionlimit(1000000)

MOD = 10 ** 9 + 7

n = int(input())

ab = [[] for _ in range(n)]

for _ in range(n-1):
    a, b = map(int, input().split())
    ab[a-1].append(b-1)
    ab[b-1].append(a-1)

def treeDP(p):
    if len(ab[p]) == 0:
        return [2,1]
    else:
        f = 1
        g = 1
        for x in ab[p]:
            ab[x].remove(p)
            temp = treeDP(x)
            f *= temp[1]
            g *= temp[0]
        f += g
        return [f % MOD, g % MOD]

print(treeDP(0)[0])