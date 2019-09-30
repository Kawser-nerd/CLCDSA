class Node(object):
    def __init__(self):
        self.in_degree = 0
        self.cur_inputs = 0
        self.dest = []

    def __str__(self):
        return "in_degree:{}, cur_inputs:{}, dests:{}".format(self.in_degree, self.cur_inputs, self.dest)

def bfs(edges, N, used):
    from collections import deque
    ret = 0
    nodes = [Node() for _ in range(N)]
    que = deque(list(range(N)))
    for e in edges:
        nodes[e[0]].dest.append(e[1])
        nodes[e[1]].in_degree += 1
    while len(que) > 0:
        n = que.popleft()
        if used[n]:
            continue
        if nodes[n].in_degree > nodes[n].cur_inputs:
            continue
        ret += 1
        used[n] = True
        for d in nodes[n].dest:
            nodes[d].cur_inputs += 1
            que.append(d)
    return ret
        
if __name__ == "__main__":
    from itertools import product, compress
    N = int(input())
    A = int(input())
    YX = []
    for _ in range(A):
        x, y = map(int, input().split())
        YX.append((y-1, x-1,))
    UV = []
    B = int(input())
    for _ in range(B):
        u, v = map(int, input().split())
        UV.append((u-1, v-1,))
    ans = 0
    for flags in map(list, product([0, 1], repeat=B)):
        edges = list(compress(UV, list(map(lambda x: x^1, flags))))
        used = [False] * N
        for e in compress(UV, flags):
            used[e[0]] = True
        ans = max(ans, bfs(YX + edges, N, used))
    print(ans)