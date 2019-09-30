n = int(input())
sus = [[] for i in range(n)]
edges = []
for i in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    sus[a].append(b)
    sus[b].append(a)
    edges.append((a, b))

def probaj(korijen):
    bio = [False for i in range(n)]
    maks = [0 for i in range(n)]

    def dfs(x, level):
        nonlocal bio
        nonlocal maks
        bio[x] = True
        djece = 0
        for y in sus[x]:
            if not bio[y]:
                dfs(y, level + 1)
                djece += 1
        maks[level] = max(maks[level], djece)
    
    if isinstance(korijen, tuple):
        k1, k2 = korijen
        bio[k1] = bio[k2] = True
        dfs(k1, 0)
        dfs(k2, 0)
        a, b = 1, 2
    else:
        dfs(korijen, 0)
        a, b = 1, 1

    for l in range(n):
        if maks[l]:
            b *= maks[l]
            a += 1
        else:
            break
    return a, b

p1 = min(probaj(i) for i in range(n))
p2 = min(probaj(e) for e in edges)
p = min(p1, p2)
print(p[0], p[1])