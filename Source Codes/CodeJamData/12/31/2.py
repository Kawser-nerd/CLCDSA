import sys

def visit(l, G):
    visited = set()
    stack = []
    stack.append(l)
    while len(stack) > 0:
        n = stack.pop()
        if n in visited:
            return True
        visited.add(n)
        for c in G[n]:
            stack.append(c)
    return False

C = int(sys.stdin.readline())
for c in range(C):
    N = int(sys.stdin.readline())
    G = []
    leaves = set(range(N))
    for n in range(N):
        parents = map(lambda p: int(p) - 1, sys.stdin.readline().split()[1:])
        G.append(parents)
        for p in parents:
            if p in leaves:
                leaves.remove(p)
    diamond_found = False
    for l in leaves:
        if visit(l, G):
            diamond_found = True
            break
    print "Case #%d: %s" % (c + 1, "Yes" if diamond_found else "No")