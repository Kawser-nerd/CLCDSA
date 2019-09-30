# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

N, x = map(int, input().split())
L = [0] + list(map(int, input().split()))

adj = [[] for _ in range(N+1)]
for _ in range(N-1):
    a, b = map(lambda x: int(x), input().split())
    adj[a].append(b)
    adj[b].append(a)


def dfs(c, p):
    if len(adj[c]) == 1:
        if L[c]:
            return 2
        else:
            return 0
    else:
        ret = 0
        for n in adj[c]:
            if n == p:
                continue
            else:
                ret += dfs(n, c)
        if ret == 0:
            if L[c]:
                return 2
            else:
                return 0
        else:
            return ret+2


ans = 0
for n in adj[x]:
    ans += dfs(n, x)
print(ans)