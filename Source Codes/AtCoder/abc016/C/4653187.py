# coding: utf-8
N, M = map(int, input().split())
data = [list(map(int, input().split())) for _ in range(M)]
tree = [[i, []] for i in range(N)]
for a, b in data:
    tree[a - 1][1].append(b - 1)
    tree[b - 1][1].append(a - 1)
for i in range(N):
    ans = []
    for j in tree[i][1]:
        for k in tree[j][1]:
            if k != i and k not in ans and k not in tree[i][1]:
                ans.append(k)
    print(len(ans))