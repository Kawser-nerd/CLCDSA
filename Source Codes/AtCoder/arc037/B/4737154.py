# -*- coding: utf-8 -*-
n,m = map(int, input().split())
edge = [[] for _ in range(n)]
for _ in range(m):
    v,u = map(int, input().split())
    v -= 1
    u -= 1
    edge[v].append(u)
    edge[u].append(v)

res = 0
label = [-1 for _ in range(n)]
while True:
    s = -1
    for i in range(n):
        if label[i]<0:
            s = i
            break
    if s<0:
        break

    st = [s]
    cnt = True
    while len(st)>0:
        v = st.pop()
        if label[v]<0:
            label[v] = res
        elif label[v]==res:
            cnt = False
        for u in edge[v]:
            if label[u]<0:
                st.append(u)
    if cnt:
        res += 1

print(res)