from priodict import priorityDictionary

def Dijkstra(G,start,end=None):
	"""
	Find shortest paths from the start vertex to all
	vertices nearer than or equal to the end.

	The input graph G is assumed to have the following
	representation: A vertex can be any object that can
	be used as an index into a dictionary.  G is a
	dictionary, indexed by vertices.  For any vertex v,
	G[v] is itself a dictionary, indexed by the neighbors
	of v.  For any edge v->w, G[v][w] is the length of
	the edge.  This is related to the representation in
	<http://www.python.org/doc/essays/graphs.html>
	where Guido van Rossum suggests representing graphs
	as dictionaries mapping vertices to lists of neighbors,
	however dictionaries of edges have many advantages
	over lists: they can store extra information (here,
	the lengths), they support fast existence tests,
	and they allow easy modification of the graph by edge
	insertion and removal.  Such modifications are not
	needed here but are important in other graph algorithms.
	Since dictionaries obey iterator protocol, a graph
	represented as described here could be handed without
	modification to an algorithm using Guido's representation.

	Of course, G and G[v] need not be Python dict objects;
	they can be any other object that obeys dict protocol,
	for instance a wrapper in which vertices are URLs
	and a call to G[v] loads the web page and finds its links.
	
	The output is a pair (D,P) where D[v] is the distance
	from start to v and P[v] is the predecessor of v along
	the shortest path from s to v.
	
	Dijkstra's algorithm is only guaranteed to work correctly
	when all edge lengths are positive. This code does not
	verify this property for all edges (only the edges seen
 	before the end vertex is reached), but will correctly
	compute shortest paths even for some graphs with negative
	edges, and will raise an exception if it discovers that
	a negative edge has caused it to make a mistake.
	"""

	D = {}	# dictionary of final distances
	P = {}	# dictionary of predecessors
	Q = priorityDictionary()   # est.dist. of non-final vert.
	Q[start] = 0
	
	for v in Q:
		D[v] = Q[v]
		if v == end: break
		
		for w in G[v]:
			vwLength = D[v] + G[v][w]
			if w in D:
				if vwLength < D[w]:
					print("Dijkstra: found better path to already-final vertex")
			elif w not in Q or vwLength < Q[w]:
				Q[w] = vwLength
				P[w] = v
	
	return (D,P)
			
def shortestPath(G,start,end):
	"""
	Find a single shortest path from the given start vertex
	to the given end vertex.
	The input has the same conventions as Dijkstra().
	The output is a list of the vertices in order along
	the shortest path.
	"""

	D,P = Dijkstra(G,start,end)
	Path = []
	while 1:
		Path.append(end)
		if end == start: break
		end = P[end]
	Path.reverse()
	return Path

import argparse

def minFlow(b1,b2):
    #b2 x0 >= b1 x0
    minflowV = min(abs(b2[1] - b1[3] - 1), abs(b1[1] - b2[3] - 1) )
    minflowH = min(abs(b2[0] - b1[2] - 1), abs(b1[0] - b2[2] - 1) )
    if (b1[0] <= b2[0] and b1[2] >= b2[0]) or \
       (b1[0] <= b2[2] and b1[2] >= b2[2]) or \
       (b2[0] <= b1[0] and b2[2] >= b1[0]) or \
       (b2[0] <= b1[2] and b2[2] >= b1[2]):
        #print("vertical")
        minflow = minflowV
    
    elif (b1[1] <= b2[1] and b1[3] >= b2[1]) or \
       (b1[1] <= b2[3] and b1[3] >= b2[3]) or \
       (b2[1] <= b1[1] and b2[3] >= b1[1]) or \
       (b2[1] <= b1[3] and b2[3] >= b1[3]):
        #print("horizontal")
        minflow = minflowH
    else:
        #print("diagonal")
        minflow = max(minflowV, minflowH)
    #print ("minflow: {}".format(minflow))
    return minflow

def main():
    # parse command line options
    parser = argparse.ArgumentParser()
    parser.add_argument('infile', type=str)
    args = parser.parse_args()
    outfile = args.infile.replace('.in', '.out')
    
    with open(args.infile) as f_in, open(outfile, 'w') as f_out:
        num_cases = int(f_in.readline().strip())
        for i in range(num_cases):
            width, height, num_buildings = [int(x) for x in f_in.readline().strip().split()]
            buildings = [[-1, 0, -1, height],[width, 0, width, height]]
            for b in range(num_buildings):
                buildings += [[int(x) for x in f_in.readline().strip().split()]]
             
            #print(buildings)
            
            G = {}
            for b in range(num_buildings + 2):
                G[b] = {}
                for b2 in range(num_buildings + 2):
                    if b==b2: continue
                    #print("finding minflow between {}, {}".format(b, b2))
                    G[b][b2] = minFlow(buildings[b],buildings[b2]);
            #print(G)
            sp = shortestPath(G, 0,1)
            result = 0
            for x in range(len(sp) - 1):
                result += G[sp[x]][sp[x+1]]
            
            outputline = "Case #{}: {}\n".format(i + 1, result)
            print(outputline)
            f_out.write(outputline)
        
# main function
if __name__ == "__main__":
    main()        