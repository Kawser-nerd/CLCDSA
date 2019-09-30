

class Edge(object):
    def __init__(self, u, v, w):
        self.source = u
        self.sink = v  
        self.capacity = w
    def __repr__(self):
        return "%s->%s:%s" % (self.source, self.sink, self.capacity)
 
class FlowNetwork(object):
    def __init__(self):
        self.adj = {}
        self.flow = {}
 
    def add_vertex(self, vertex):
        self.adj[vertex] = []
 
    def get_edges(self, v):
        return self.adj[v]
 
    def add_edge(self, u, v, w=1):
        if u == v:
            raise ValueError("u == v")
        edge = Edge(u,v,w)
        redge = Edge(v,u,0)
        edge.redge = redge
        redge.redge = edge
        self.adj[u].append(edge)
        self.adj[v].append(redge)
        self.flow[edge] = 0
        self.flow[redge] = 0
 
    def find_path(self, source, sink, path):
        if source == sink:
            return path
        for edge in self.get_edges(source):
            residual = edge.capacity - self.flow[edge]
            if residual > 0 and edge not in path:
                result = self.find_path( edge.sink, sink, path + [edge])
                if result != None:
                    return result
 
    def max_flow(self, source, sink):
        path = self.find_path(source, sink, [])
        while path != None:
            residuals = [edge.capacity - self.flow[edge] for edge in path]
            flow = min(residuals)
            for edge in path:
                self.flow[edge] += flow
                self.flow[edge.redge] -= flow
            path = self.find_path(source, sink, [])
        return sum(self.flow[edge] for edge in self.get_edges(source))

def relabel_to_front(C, source, sink):
 n = len(C) # C is the capacity matrix
 F = [[0] * n for _ in xrange(n)]
 # residual capacity from u to v is C[u][v] - F[u][v]

 height = [0] * n # height of node
 excess = [0] * n # flow into node minus flow from node
 seen   = [0] * n # neighbours seen since last relabel
 # node "queue"
 nodelist = [i for i in xrange(n) if i != source and i != sink]

 def push(u, v):
	 send = min(excess[u], C[u][v] - F[u][v])
	 F[u][v] += send
	 F[v][u] -= send
	 excess[u] -= send
	 excess[v] += send

 def relabel(u):
	 # find smallest new height making a push possible,
	 # if such a push is possible at all
	 min_height = 10000000000
	 for v in xrange(n):
		 if C[u][v] - F[u][v] > 0:
			 min_height = min(min_height, height[v])
			 height[u] = min_height + 1

 def discharge(u):
	 while excess[u] > 0:
		 if seen[u] < n: # check next neighbour
			 v = seen[u]
			 if C[u][v] - F[u][v] > 0 and height[u] > height[v]:
				 push(u, v)
			 else:
				 seen[u] += 1
		 else: # we have checked all neighbours. must relabel
			 relabel(u)
			 seen[u] = 0

 height[source] = n   # longest path from source to sink is less than n long
 excess[source] = 10000000000 # send as much flow as possible to neighbours of source
 for v in xrange(n):
	 push(source, v)

 p = 0
 while p < len(nodelist):
	 u = nodelist[p]
	 old_height = height[u]
	 discharge(u)
	 if height[u] > old_height:
		 nodelist.insert(0, nodelist.pop(p)) # move to front of list
		 p = 0 # start from front of list
	 else:
		 p += 1

 return sum(F[source])
    
from collections import defaultdict as ddic
def solve(N,A):
    words = set([])
    for sentence in A:
        for word in sentence.split():
            words.add(word)
    words = list(words)
    word_dic = {}
    for ix,word in enumerate(words):
        word_dic[word] = ix
    AA = [[0 for i in xrange(len(A)+len(words))] for i in xrange(len(A)+len(words))]
    #SENTENCES FIRST
    for ix,sentence in enumerate(A):
        for word in sentence.split():
            jx = word_dic[word]
            AA[ix][N+jx] = 1
            AA[N+jx][ix] = 1
    #for i in AA: print i #print AA
    return relabel_to_front(AA,0,1)
    """
    Z = FlowNetwork()
    words = set([])
    for sentence in A:
        for word in sentence.split():
            words.add(word)
    for word in words:
        Z.add_vertex(word)
        
    for ix,sentence in enumerate(A):
        Z.add_vertex(str(ix)+';'+sentence)
        for word in set(sentence.split()):
            #print 'adding',word,'@@@',sentence
            Z.add_edge(word,str(ix)+';'+sentence,1)
            Z.add_edge(str(ix)+';'+sentence,word,1)
    LL = len(A)-1
    for i in Z.flow: print i
    #for i in Z.adj: print i
    #return Z.max_flow(str(0)+';'+A[0],str(LL)+';'+A[-1])"""
            
    


########
fo = open('out.txt','w')
with open('in.txt','r') as fi:
    rr = lambda: fi.readline().strip()
    rrI = lambda: int(rr())
    rrM = lambda: map(int,rr().split())
    for tc in xrange(rrI()):
        N = rrI()
        A = [rr() for i in xrange(N)]
        zetaans = solve(N,A)
        zeta = "Case #%i: "%(tc+1) + str(zetaans)
        print zeta
        fo.write(zeta+'\n')
fo.close()
