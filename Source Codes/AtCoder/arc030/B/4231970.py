N, start = map(int, input().split())
start -= 1
inputs = [int(i) for i in input().split()]

nodes = [[] for _ in range(N)]
for i in range(N-1):
    first, latter = map(lambda x: int(x) - 1, input().split())
    nodes[first].append(latter)
    nodes[latter].append(first)

visited = [False] * N
ans = 0

def dfs(start):
    global ans
    visited[start] = True
    exist = inputs[start]
    for node in nodes[start]:
        if visited[node]:
            continue
        if dfs(node):
            ans += 2
            exist = 1
    return exist

dfs(start)

print(ans)