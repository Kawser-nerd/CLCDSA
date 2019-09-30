import sys

sys.setrecursionlimit(100000)


def dfs(v, p):
    result = sum(dfs(c, v) for c in edges[v] if c != p)
    if result >= 2:
        print('First')
        exit()
    return not result


n = int(input())
if n % 2:
    print('First')
    exit()

edges = [set() for _ in range(n)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edges[a].add(b)
    edges[b].add(a)

print('First' if dfs(0, None) else 'Second')