import sys

sys.setrecursionlimit(10000)

def sol(n, f):
    vis = [0] * n
    res = 0

    def dfs(i, l):
        if vis[i]:
            # print (l, i, vis[i])
            r = l - vis[i]
        else:
            vis[i] = l
            r = dfs(f[i], l + 1)
        vis[i] = 2 * n
        return r

    for i in xrange(n):
        if not vis[i]:
            res = max(dfs(i, 1), res)

    def lc(i, ii):
        q = [i]
        l = [0] * n
        for x in q:
            for j, k in enumerate(f):
                if k == x and j != ii:
                    q.append(j)
                    l[j] = l[x] + 1
        return max(l)

    np = 0
    for j, i in enumerate(f):
        if f[i] == j and j < i:
            np += lc(i, j) + lc(j, i) + 2

    return max(res, np)


rl = lambda: map(int, raw_input().split())

t = input()
for i in xrange(t):
    n = input()
    f = [x - 1 for x in rl()]
    print "Case #%d:" % (i + 1), sol(n, f)
