n,m = map(int,input().split())
maps = [[] for _ in range(n)]
for _ in range(m):
    a,b = map(int,input().split())
    a,b = a-1,b-1
    maps[a].append(b)
    maps[b].append(a)
for i in range(n):
    frends = maps[i]
    J = set()
    for j in frends:
        frendss = maps[j]
        for k in frendss:
            if k not in frends:
                J.add(k)
    try:
        J.remove(i)
    except:
        pass
    print(len(J))