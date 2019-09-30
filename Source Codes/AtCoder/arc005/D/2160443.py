# seishin.py
from collections import deque
*B, = map(int, input())
C = B[1:]
*price, = map(int, input())
price.reverse()

que = deque()

# ?????????????
# d[p, q] = C
#  - B??? 10*q + p ?????????(???)???? C
#    ?. B = "0145" ?? d[4, 1] = [5, 5, 4]
def make(l):
    d = {(0, 0): []}
    que.append((0, 0))
    # BFS
    while que:
        v = p, q = que.popleft()
        for k in C:
            if p + k >= 10:
                key = ((p + k) % 10, q + 1)
            else:
                key = (p + k, q)
            if key not in d:
                d[key] = d[v] + [k]
                if len(d[v]) < l:
                    que.append(key)
    m = [[] for i in range(10)]
    for p, q in d:
        m[p].append((q, d[p, q]))
    return d, m


N = len(price)
# 0?1??????????9???????????????
# ???????????
K = 10
d, m = make(K)

memo = {}
INF = 10**9
# price??????????? D_1, ..., D_k ??? (D_1 + ... + D_k = price)
# ??? D_i ?j????? di_j ??
#
# ??? V = di_1 + di_2 + ... + di_k + s ????
# dfs(i, s) ?? price?i????? (V % 10) ???????? d_1, ..., d_k ?????
#
# ???????????????? dfs(i+1, <???????> = (V / 10)) ?????????
#
# ???:
#  - ('='????)???
#  - D_1, ..., D_k ??????
def dfs(i, s):
    if (i, s) in memo:
        return memo[i, s]
    need = price[i] - s
    if i == N-1:
        if (need, 0) in d:
            # V == price[i] ??? di_1, ..., di_k ???
            # ???? (???????)
            # ?. 2727 = 0909 + 0909 + 0909 (4???0)
            return len(d[need, 0])*2-1, [[e] for e in d[need, 0]]
        return None, None
    res = INF; cur = None
    for q, L in m[need % 10]:
        # i??????? (price[i] - s)%10 ??????????
        if len(L) <= K:
            # dfs(i+1, q): price[i] - s >= 0 ??
            # dfs(i+1, q+1): price[i] - s < 0 ?? (V (mode 10) == price[i] ?????????????????)
            # ????r: i+1??????????????? D_1, ..., D_k ??
            c, r = dfs(i+1, q+1 if need < 0 else q)
            if r is None: continue
            *t, = map(list, r)
            if len(L) < len(r):
                # i+1?????????????????? D_j ?????????????
                # len(L)????D_j???????? L[j] ??????
                for j in range(len(L)):
                    t[j].append(L[j])
                # ???????????? '0' ??????
                for j in range(len(L), len(r)):
                    t[j].append(0)
                c += len(r)
            else:
                # i+1?????????????????? D_j ?????????????
                # len(r)????D_j???????? L[j] ??????
                for j in range(len(r)):
                    t[j].append(L[j])
                # ????????? D_j ????????? L[j] ???
                for j in range(len(r), len(L)):
                    t.append([L[j]])
                    c += 1 # '+' ?????????
                c += len(L)
            if c < res:
                res = c
                cur = t
    memo[i, s] = res, cur
    return res, cur

sz, res = dfs(0, 0)
ans = []
for D in res:
    ans.append("".join(map(str, D)))
ans = "+".join(ans)
if len(res) > 1:
    ans += "="
print(ans)