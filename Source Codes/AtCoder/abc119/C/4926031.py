import itertools

N, A, B, C = map(int, input().split())
t = [A, B, C]

l = []
for i in range(N):
    l.append(int(input()))

ans = 999999999
count = 0

products = list(itertools.product([0, 1, 2, 3], repeat=N))
# [0, 1, 2, 3]????N???????????????????????
for p in products:
    scores_g = [[0, 0], [0, 0], [0, 0], [0, 0]]
    for i in range(len(p)):
        scores_g[p[i]][0] += l[i]
        scores_g[p[i]][1] += 1
    for g in range(3):
        if scores_g[g][1] == 0:
            count = 999999999
            continue
        else:
            count += abs(scores_g[g][0] - t[g]) + (scores_g[g][1] - 1) * 10
    if ans > count:
        ans = count
    count = 0

print(ans)