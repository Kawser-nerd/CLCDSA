from collections import deque
def dfs(path):
    global visited, A
    q = deque([])
    q.append(path)
    for d in A[1]:
        q.append(d)
    while q:
        p = q.pop()
        for d in A[p]:
            if visited[d] == True:
                pass
            else:
                visited[d] = True


if __name__ == '__main__':
    N, M = map(int, input().split())
    A = [[] for _ in range(N+1)]
    for _ in range(M):
        a, b = map(int, input().split())
        A[a].append(b)
        A[b].append(a)
    visited = [False] * (N+1)
    dfs(1)
    if visited[N]:
        print("POSSIBLE")
    else:
        print("IMPOSSIBLE")