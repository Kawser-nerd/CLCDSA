import sys

def getWords():
    return sys.stdin.readline().strip().split()

def getInts():
    return [int(i) for i in getWords()]

def getInt():
	i = getInts()
	assert len(i)==1
	return i[0]

from Queue import Queue

T = getInt()

for caseNo in xrange(1,T+1):
    N = getInt()
    
    sentences = [ getWords() for i in range(N) ]
    words = sorted(set(sum(sentences, [])))
    W = len(words)
    wordIx = dict(zip(words, xrange(W)))

    s = [ [ wordIx[w] for w in snt ] for snt in sentences]
    
    V = 2*W + 2

    adj = [set() for i in range(V)]
    radj = [set() for i in range(V)]
    used = dict()
    
    def add_edge(i,j):
        adj[i] |= set([j])
        radj[j] |= set([i])
        used[(i,j)] = False

    for j in s[0]:
        add_edge(V-2, 2*j)

    for i in s[1]:
        add_edge(2*i+1, V-1)

    for ss in s[2:]:
        for i in ss:
            for j in ss:
                if i != j:
                    add_edge(2*i+1, 2*j)

    for i in range(W):
        add_edge(2*i, 2*i+1)

    def BFS(s, t):
        d = dict()
        prev = dict()
        q = Queue()
        q.put((s,0,None))
        while t not in d:
            if q.empty():
                return None
            v, dd, prv = q.get()
            if v in d:
                continue
            d[v] = dd
            prev[v] = prv
            for u in adj[v]:
                if u not in d and not used[(v,u)]:
                    q.put((u,dd+1,v))
            for u in radj[v]:
                if u not in d and used[(u,v)]:
                    q.put((u,dd+1,v))
        path = []
        v = t
        while v!=s:
            path.append(v)
            v = prev[v]
        path.append(s)
        return path[::-1]
    
    flow = 0
    while True:
        path = BFS(V-2, V-1)
        if path == None:
            break
        
        flow += 1
        for u,v in zip(path[:-1],path[1:]):
            if v in adj[u]:
                assert not used[(u,v)]
                used[u,v]=True
            else:
                assert used[(v,u)]
                used[v,u]=False

    print "Case #%d: %d"%(caseNo, flow)
    print >>sys.stderr, "Case #%d: %d"%(caseNo, flow)
    sys.stderr.flush()
