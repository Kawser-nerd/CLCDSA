n, m = map(int, input().split())
datas = dict()
friends = dict()

# ???????????
for i in range(n):
    datas[i + 1] = []
    friends[i + 1] = []

# ???????????
for r in range(m):
    a, b = map(int, input().split())
    datas[a].append(b)
    datas[b].append(a)

# ??????????
for i in range(1, n + 1):
    # ????????
    removements = list(datas[i])
    removements.append(i)
    for j in datas[i]:
        for k in datas[j]:
            if k not in friends[i] and k not in removements:
                friends[i].append(k)

# ?????
for i in range(n):
    print(len(friends[i + 1]))