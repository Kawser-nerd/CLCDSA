# C[n,v] = minimum number of changes for node n (goal is v)
# C[n,1] = min { C[L,1]+C[R,1], C[L,1]+C[R,0], C[L,0]+C[R,1] } if node is OR
#        = min { C[L,1]+C[R,1], C[L,1]+C[R,0]+1, C[L,0]+C[R,1]+1 } if AND
# C[n,0] = min { C[L,0]+C[R,0]+1, C[L,0]+C[R,1]+1, C[L,1]+C[R,0]+1 } if OR
#        = min { C[L,0]+C[R,0], C[L,0]+C[R,1], C[L,1]+C[R,0]+1 } if AND
# C[n,v] = 0 for leaf node n which is v
#        = infinity for leaf node n which is not v

def process(nodes, changable, goal):
    inf = 99999999
    nnodes = len(nodes)
    table = [None] * nnodes
    for i in xrange(nnodes - 1, -1, -1):
        if i < (nnodes - 1) / 2: # inferior
            left = i * 2 + 1
            right = i * 2 + 2
            if changable[i]:
                if nodes[i]: # AND gate
                    value = (min(table[left][0] + table[right][0],
                                 table[left][0] + table[right][1],
                                 table[left][1] + table[right][0]),
                             min(table[left][1] + table[right][1],
                                 table[left][1] + table[right][0] + 1,
                                 table[left][0] + table[right][1] + 1))
                else:
                    value = (min(table[left][0] + table[right][0],
                                 table[left][0] + table[right][1] + 1,
                                 table[left][1] + table[right][0] + 1),
                             min(table[left][1] + table[right][1],
                                 table[left][1] + table[right][0],
                                 table[left][0] + table[right][1]))
            else:
                if nodes[i]: # AND gate
                    value = (min(table[left][0] + table[right][0],
                                 table[left][0] + table[right][1],
                                 table[left][1] + table[right][0]),
                             table[left][1] + table[right][1])
                else:
                    value = (table[left][0] + table[right][0],
                             min(table[left][1] + table[right][1],
                                 table[left][1] + table[right][0],
                                 table[left][0] + table[right][1]))
        else:
            if nodes[i]:
                value = (inf, 0)
            else:
                value = (0, inf)
        table[i] = value
    return table[0][goal]

import sys
next = iter(sys.stdin).next
ncases = int(next())
for i in xrange(ncases):
    nnodes, goal = map(int, next().split())
    nodes = []
    changable = []
    for k in xrange(nnodes):
        if k < (nnodes - 1) / 2:
            g, c = map(int, next().split())
            nodes.append(g); changable.append(c)
        else:
            nodes.append(int(next()))
    minchanges = process(nodes, changable, goal)
    if minchanges > 9999999:
        print 'Case #%d: IMPOSSIBLE' % (i+1)
    else:
        print 'Case #%d: %d' % (i+1, minchanges)
    sys.stdout.flush()

