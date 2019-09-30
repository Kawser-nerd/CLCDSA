N, M = map(int, input().split())
group = [[i + 1] for i in range(N)]
#print(group)
for i in range(M):
    x, y = map(int, input().split())
    group[x - 1].append(y)
    group[y - 1].append(x)
#print(group)
ans = 1
for i in range(1 << N):
    sub_group = []
    for j in range(N):
        if (i >> j) & 1:
            # ??????????
            # ??????
            sub_group.append(j + 1)
    if len(sub_group) > ans:
        # ?????????
        # ?????????????
        # ??
        if all(all(k in group[j - 1] for j in sub_group) for k in sub_group):
            ans = len(sub_group)

print(ans)