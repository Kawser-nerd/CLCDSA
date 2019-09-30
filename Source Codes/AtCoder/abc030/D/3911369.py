N, a = map(int, input().split())
k = int(input())

g = {i+1: v for i,v in enumerate([int(i) for i in input().split()])}

visited = set()
p = []

def dfs(i):
    if i in visited:
        p.append(i)
        return 
    visited.add(i)
    p.append(i)
    dfs(g[i])

dfs(a)


def s(a):
    i = a.index(a[-1])
    return len(a) - i -1


if k - len(p) + 1 <= 0:
    print(p[k])
else:
    k = k - len(p) + 1
    k = k % s(p)
    i = p.index(p[-1])
    print(p[i+k])