import psyco
psyco.full()

INF = 2**30

def calc(nodes, u, V, memo={}):
    if (u, V) in memo:
        return memo[(u, V)]

    if type(nodes[u]) == int:
        if nodes[u] == V:
            return 0
        else:
            return INF

    if nodes[u][1] == 'AND':
        if V == 1:
            res = calc(nodes, u*2, 1, memo) + calc(nodes, u*2+1, 1, memo)
        else:
            res = min(calc(nodes, u*2, 0, memo), calc(nodes, u*2+1, 0, memo))
    else:
        if V == 1:
            res = min(calc(nodes, u*2, 1, memo), calc(nodes, u*2+1, 1, memo))
        else:
            res = calc(nodes, u*2, 0, memo) + calc(nodes, u*2+1, 0, memo)

    res2 = INF
    if nodes[u][0] == 1:
        if nodes[u][1] == 'OR':
            if V == 1:
                res2 = 1 + calc(nodes, u*2, 1, memo) + calc(nodes, u*2+1, 1, memo)
            else:
                res2 = 1 + min(calc(nodes, u*2, 0, memo), calc(nodes, u*2+1, 0, memo))
        else:
            if V == 1:
                res2 = 1 + min(calc(nodes, u*2, 1, memo), calc(nodes, u*2+1, 1, memo))
            else:
                res2 = 1 + calc(nodes, u*2, 0, memo) + calc(nodes, u*2+1, 0, memo)

    res = min(res, res2)

    memo[(u, V)] = res
    return res


def solve():
    for case in xrange(input()):
        M, V = [int(s) for s in raw_input().split()]
        nodes = [None]
        for i in xrange((M - 1) / 2):
            g, c = [int(s) for s in raw_input().split()]
            nodes.append((c, 'AND' if g == 1 else 'OR'))
        for i in xrange((M + 1) / 2):
            l = input()
            nodes.append(l)

        res = calc(nodes, 1, V, {})
        if res < INF:
            res = str(res)
        else:
            res = 'IMPOSSIBLE'

        print 'Case #%d: %s' % (case+1, res)

solve() # so that psyco can do its magic
