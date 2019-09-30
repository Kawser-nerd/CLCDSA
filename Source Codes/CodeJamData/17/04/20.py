import sys
from collections import defaultdict
#http://www.ics.uci.edu/~eppstein/PADS/
#David Eppstein's python library
from pads import BipartiteMatching

def next_line():
    return input_file.readline().rstrip()

input_file = open(sys.argv[1])
for case in range(1, int(next_line())+1):
    print "Case #%s:" % (case),
    N, M = map(int, next_line().split())
    #d = {}
    delete_rook = []
    delete_bishop = []
    points = 0
    models = {}
    for i in xrange(M):
        s, i, j = next_line().split()
        #d[(int(i), int(j))] = s
        i, j = int(i) - 1, int(j) - 1
        models[(i, j)] = s
        if s in "ox":
            delete_rook.append('r%s' % i)
            delete_rook.append('c%s' % j)
            points += 1
        if s in "o+":
            delete_bishop.append('d%s' % (i+j))
            delete_bishop.append('D%s' % (i-j))
            points += 1
    rook = ['r%s' % i for i in xrange(N)] +\
           ['c%s' % i for i in xrange(N)]
    rook = set(rook) - set(delete_rook)
    rook_edges = [(v, w) for v in rook if v[0] == 'r'
                  for w in rook if w[0] == 'c']
    rook_graph = defaultdict(list)
    for v, w in rook_edges:
        rook_graph[v].append(w)
    rook_matching = BipartiteMatching.matching(rook_graph)[0]

    bishop = ['d%s' % i for i in xrange(0, 2*N+1)] +\
             ['D%s' % i for i in xrange(-N+1, N)]
    bishop = set(bishop) - set(delete_bishop)
    bishop_edges = []
    for i in xrange(N):
        for j in xrange(N):
            if "d%s" % (i+j) in bishop and "D%s" % (i-j) in bishop:
                bishop_edges.append(("d%s" % (i+j), "D%s" % (i-j)))
    bishop_graph = defaultdict(list)
    for v, w in bishop_edges:
        bishop_graph[v].append(w)
    bishop_matching = BipartiteMatching.matching(bishop_graph)[0]
    #print rook_matching
    #print bishop_matching
    print points + len(rook_matching) + len(bishop_matching),
    orig_models = models.copy()
    for j, i in rook_matching.items():
        i, j = int(i[1:]), int(j[1:])
        if (i, j) not in models:
            models[(i, j)] = 'x'
        else:
            assert(models[(i, j)] == '+')
            models[(i, j)] = 'o'
    for D, d in bishop_matching.items():
        D, d = int(D[1:]), int(d[1:])
        i, j = (d + D) / 2, (d - D) / 2
        assert(i >= 0 and j >= 0)
        if (i, j) not in models:
            models[(i, j)] = '+'
        else:
            assert(models[(i, j)] == 'x')
            models[(i, j)] = 'o'
    """
    for i in range(N):
        print "".join(orig_models.get((i,j), " ") for j in range(N))
        break
    print
    for i in range(N):
        print "".join(models.get((i,j), " ") for j in range(N))
    """
    diff = 0
    for (i, j), s in models.items():
        if orig_models.get((i, j)) != s:
            diff += 1
    print diff
    for (i, j), s in models.items():
        if orig_models.get((i, j)) != s:
            print s, i+1, j+1
