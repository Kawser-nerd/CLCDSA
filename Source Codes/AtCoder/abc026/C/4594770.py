n = int(input())
d = []
for i in range(n - 1):
    d.append(input())
# [d1, d2, d3, ..., dN]
d = [int(m) for m in d]#int????
b = [0]*(n + 1)
b[1] = [1, 1]
for i in range(n - 1):
    b[i + 2] = [i + 2, d[i]]
payli = [[i, 1] for i in range(n + 1)]
mmp = [[] for i in range(n + 1)]
for j in reversed(range(1, n + 1)):
    for i in range(2, n + 1):
        if j == b[i][1]:
            mmp[j].append(payli[i][1])
    if mmp[j] != []:
        payli[j][1] = max(mmp[j]) + min(mmp[j]) + 1
print(payli[1][1])