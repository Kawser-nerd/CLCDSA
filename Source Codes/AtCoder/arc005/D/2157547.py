# seishin.py
from collections import deque
*B, = map(int, input())
C = B[1:]
*price, = map(int, input())
price.reverse()

que = deque()

def make(l):
    d = {(0, 0): []}
    que.append((0, 0))
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

d, m = make(10)

N = len(price)
def solve(k):
    memo = {}
    INF = 10**9
    def dfs(i, s):
        if (i, s) in memo:
            return memo[i, s]
        need = price[i] - s
        if i == N-1:
            if (need, 0) in d:
                return len(d[need, 0])*2-1, [[e] for e in d[need, 0]]
            return None, None
        res = INF; cur = None
        for q, L in m[need % 10]:
            if len(L) <= k:
                c, r = dfs(i+1, q+1 if need < 0 else q)
                if r is None: continue
                *t, = map(list, r)
                if len(L) < len(r):
                    for j in range(len(L)):
                        t[j].append(L[j])
                    for j in range(len(L), len(r)):
                        t[j].append(0)
                    c += len(r)
                else:
                    for j in range(len(r)):
                        t[j].append(L[j])
                    for j in range(len(r), len(L)):
                        t.append([L[j]])
                        c += 1 # '+'
                    c += len(L)
                if c < res:
                    res = c
                    cur = t
        memo[i, s] = res, cur
        return res, cur
    return dfs(0, 0)
sz, res = solve(10)
ans = []
for D in res:
    ans.append("".join(map(str, D)))
ans = "+".join(ans)
assert eval(ans) == eval("".join(map(str, price[::-1])))
assert len(ans) == sz
if len(res) > 1:
    ans += "="
print(ans)