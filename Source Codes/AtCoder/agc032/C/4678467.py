from sys import setrecursionlimit
setrecursionlimit(10 ** 9)

n, m = [int(i) for i in input().split()]
E = [[] for i in range(n+1)]
used = [False] * (n + 1)
IN = [0] * (n + 1)

for i in range(m):
    a, b = [int(i) for i in input().split()]
    E[a].append(b)
    E[b].append(a)
    IN[a] += 1
    IN[b] += 1

cnt_4 = 0
cnt_6 = 0
v_4 = []
for j, i in enumerate(IN[1:]):
    if i % 2 == 1 or i == 0:
        print('No')
        exit()
    if i >= 4:
        cnt_4 += 1
        v_4.append(j + 1)
    if i >= 6:
        cnt_6 += 1

def dfs(p, v):
    if v == v_4[0]:
        return v_4[0]
    if v == v_4[1]:
        return v_4[1]

    for e in E[v]:
        if e == p:
            continue
        return dfs(v, e)

if cnt_4 > 2 or cnt_6 >= 1:
    print('Yes')
elif cnt_4 == 2:
    if all(dfs(v_4[0], e) == v_4[1] for e in E[v_4[0]]):
        print('No')
    else:
        print('Yes')

else:
    print('No')