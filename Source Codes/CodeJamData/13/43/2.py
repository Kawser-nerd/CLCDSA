from heapq import *

def infer_edges(A):
    edges = []
    for j in xrange(0, n):
        seen_prev = False
        for i in xrange(j-1, -1, -1):
            if A[i] >= A[j]:
                edges.append((j, i))
            elif A[i] + 1 == A[j]:
                if not seen_prev:
                    seen_prev = True
                    edges.append((i, j))
    return edges

rl = lambda: raw_input().strip()
cases = int(rl())
for cc in xrange(cases):
    n = int(rl())
    A = map(int, rl().split())
    B = map(int, rl().split())

    edges1 = infer_edges(A)
    edges2 = infer_edges(list(reversed(B)))
    edges2 = [(n - 1 - i, n - 1 - j)
              for i, j in edges2]

    out = [[] for i in xrange(n)]
    ind = [0] * n
    for a, b in edges1 + edges2:
        out[a].append(b)
        ind[b] += 1
    taken = [False] * n
    X = [0] * n
    for num in xrange(1, n+1):
        for i in xrange(n):
            if ind[i] == 0 and not taken[i]:
                taken[i] = True
                X[i] = num
                for j in out[i]:
                    ind[j] -= 1
                break
    print 'Case #%d: %s' % (cc+1, ' '.join(map(str, X)))



