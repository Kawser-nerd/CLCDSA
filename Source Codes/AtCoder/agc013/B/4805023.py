import sys
sys.setrecursionlimit(2*10**5)

# ??
N, M = map(int, input().split())
A, B = zip(*(map(int, input().split()) for _ in range(M)))

# ??????????????
E = [[] for _ in range(N + 1)]
for a, b in zip(A, B):
    E[a].append(b)
    E[b].append(a)

# ????????????????
v = [i == 1 for i in range(N + 1)]


# ???????????????????
def dfs(i, p):
    for j in E[i]:
        if not v[j]:
            v[j] = True
            p.append(j)
            return dfs(j, p)
    else:
        return p


# Hamiltonish Path ????
p = list(reversed(dfs(1, []))) + [1] + dfs(1, [])

# ??
ans = '{}\n{}'.format(len(p), ' '.join(map(str, p)))
print(ans)