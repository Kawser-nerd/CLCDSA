import sys
from itertools import permutations

T = int(sys.stdin.readline().strip())

def possible(order):
    stack = [order[0]]
    for u in order[1:]:
        while not u in edges[stack[-1]]:
            stack.pop()
            if len(stack) == 0:
                return False
        stack.append(u)
    return True
    

for t in range(T):
    N, M = tuple(int(i) for i in sys.stdin.readline().strip().split())
    zips = list(sys.stdin.readline().strip() for _ in range(N))
    edges = list(list() for _ in range(N))
    for i in range(M):
        u, v = tuple(int(i) for i in sys.stdin.readline().strip().split())
        edges[u-1].append(v-1)
        edges[v-1].append(u-1)
    visited = list(False for _ in range(N))

    result = 'a'
    assert 'a' > '9'

    for order in permutations(list(range(N))):
        if possible(order):
            s = "".join(zips[i] for i in order)
            result = min(result, s)

    print("Case #%d: %s" % (t+1, result))
