import queue

G = [[0 for _ in range(101)] for __ in range(101)]
n, g, e = [int(x) for x in input().split()]

for x in input().split():
    pi = int(x)
    G[pi][100] = G[100][pi] = 1

for _ in range(e):
    ai, bi = [int(x) for x in input().split()]
    G[ai][bi] = G[bi][ai] = 1


def find_path():
    q = queue.Queue()
    visited = {0: 0}
    q.put(0)
    while not q.empty():
        last = q.get()
        if last == 100:
            path = [last]
            while last != 0:
                prev = visited[last]
                path.insert(0, prev)
                last = prev
            return path
        for to, gij in enumerate(G[last]):
            if gij > 0 and to not in visited:
                visited[to] = last
                q.put(to)
    return None


while True:
    path = find_path()
    if path is None:
        break
    for i, j in zip(path[:-1], path[1:]):
        G[i][j] -= 1
        G[j][i] += 1

print(sum(Gi[0] == 2 for Gi in G))