g = []
states = []


def visit(a, b):
    if states[b] == 2:
        # visited
        return False
    if states[b] == 1:
        # visiting
        return True
    # not visited
    states[b] = 1
    res = False
    for c in g[b]:
        if c != a:
            res = visit(b, c) or res
    states[b] = 2
    return res


def main():
    global g, states
    n, m = map(int, input().split())
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        g[u - 1].append(v - 1)
        g[v - 1].append(u - 1)
    states = [0 for _ in range(n)]
    res = 0
    for i in range(n):
        if states[i] == 0:
            if not visit(None, i):
                res += 1

    print(res)


if __name__ == "__main__":
    main()