import sys
sys.setrecursionlimit(10**7)

mod = 10**9 + 7

n = int(input())
graph = [[] for _ in range(n)]
for i in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)

# color {0: white, 1: black}

white = [-1] * n
black = [-1] * n

def f(node, color, parent=-1):
    res = 1
    if color == 0:
        if white[node] != -1:
            return white[node]
        for next_node in graph[node]:
            if next_node == parent:
                continue
            res *= (f(next_node, 0, node) + f(next_node, 1, node))
            res %= mod
        white[node] = res
        return res
    else:
        if black[node] != -1:
            return black[node]
        for next_node in graph[node]:
            if next_node == parent:
                continue
            res *= f(next_node, 0, node)
            res %= mod
        black[node] = res
        return res

print((f(0, 0) + f(0, 1)) % mod)