import sys
import heapq

class Graph(object):
    def __init__(self, nodes, edges):
        self.nodes, self.edges = nodes, edges
        self.edge_map = {}
        for node in self.nodes:
            self.edge_map[node] = []
        for edge in self.edges:
            self.edge_map[edge.source].append(edge)
    
    def floyd_warshall(self):
        matrix = [[1000000 for node in self.nodes] for node in self.nodes]
        for edge in self.edges:
            matrix[edge.source.index][edge.target.index] = min(matrix[edge.source.index][edge.target.index], edge.length)
        for k in xrange(len(self.nodes)):
            for i in xrange(len(self.nodes)):
                for j in xrange(len(self.nodes)):
                    matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j])
        return matrix
    
    def do_dijkstra(self, source, sink = None):
        dist = {}
        for node in self.nodes:
            dist[(source, node)] = 20000000
            dist[(node, node)] = 0
        for edge in self.edges:
            dist[(edge.source, edge.target)] = edge.length
        prev = {}  
        visited = {}
        for node in self.nodes:
            visited[node] = False
        path_cap = 0 
        heap = []
        heapq.heappush(heap, (20000000, source, None))
        while len(heap) > 0:
            aux = heapq.heappop(heap)
            where = aux[1]
            cost = aux[0]
            if visited[where]:
                continue
            prev[where] = aux[2]
            if sink and where == sink:
                path_cap = cost
                break
            visited[where] = True
            for edge in self.edge_map[where]:                
                if dist[(where, edge.target)] + dist[(source, where)] < dist[(source, edge.target)]:
                    dist[(source, edge.target)] = dist[(where, edge.target)] + dist[(source, where)]
                    prev[edge.target.index] = where
                heapq.heappush(heap, (dist[(where, edge.target)] + dist[(source, where)], edge.target, where))
        return (prev, dist)

    def dijkstra_shortest_path(self, source, sink):
        prev, dist = self.do_dijkstra(source, sink)
        where = sink
        path = [where]
        while prev.has_key(where):
            previous = prev[where]
            if previous is not None:
                path.append(previous)
            where = previous
        return path

    def dijkstra_shortest_path_length(self, source, sink):
        prev, dist = self.do_dijkstra(source, sink)
        return dist[(source,sink)]
    
    def dijkstra_all_shortest_path_lengths(self, source):
        prev, dist = self.do_dijkstra(source)
        return [(n, dist[(source, n)]) for n in self.nodes]

class Node:
    def __init__(self, char, row, col, index):
        self.char = char
        self.row = row
        self.col = col
        self.index = index

    def __repr__(self):
        return "%s %d %d %d" % (self.char, self.row, self.col, self.index)

class Edge:
    def __init__(self, source, target, length):
        self.source = source
        self.target = target
        self.length = length
        
    def __repr__(self):
        return "%d %d %d" % (self.source.index, self.target.index, self.length)

class Case:
    def __init__(self, s, caseNum):
        self.caseNum = caseNum
        self.rows, self.cols = map(int, s.read().split(" "))
        board = s.readList(self.rows)
        self.altitudes = [map(int, row.split(" ")) for row in board]

    def solve(self):
        moves = [(-1,0), (0,-1), (0,1), (1,0)]
        nodes = []
        nodes_grid = [[None for x in xrange(self.cols)] for y in xrange(self.rows)]
        edges = []
        i = 0
        for r in xrange(self.rows):
            for c in xrange(self.cols):
                nodes.append(Node(self.altitudes[r][c], r, c, i))
                nodes_grid[r][c] = nodes[i]
                i += 1
        i = 0
        for r in xrange(self.rows):
            for c in xrange(self.cols):
                next_node = None
                min_altitude = 1000000
                for move in moves:
                    nextr = r + move[0]
                    nextc = c + move[1]
                    if nextr < 0 or nextr >= self.rows or nextc < 0 or nextc >= self.cols:
                        continue
                    if self.altitudes[nextr][nextc] >= self.altitudes[r][c]:
                        continue
                    if self.altitudes[nextr][nextc] < min_altitude:
                        min_altitude = self.altitudes[nextr][nextc]
                        next_node = nodes_grid[nextr][nextc]
                if next_node is not None:
                    edges.append(Edge(nodes[i], next_node, 1))
                    edges.append(Edge(next_node, nodes[i], 1))
                i += 1
        self.drainages = [["#" for c in xrange(self.cols)] for r in xrange(self.rows)]
        g = Graph(nodes, edges)
        letters = 'abcdefghijklmnopqrstuvwxyz'
        index = 0
        work_to_do = True
        while work_to_do:
            work_to_do = False
            for r in xrange(self.rows):
                for c in xrange(self.cols):
                    if self.drainages[r][c] == "#":
                        self.drainages[r][c] = letters[index]
                        work_to_do = True
                        node_costs = g.dijkstra_all_shortest_path_lengths(nodes[r*self.cols+c])
                        for cost in node_costs:
                            if cost[1] < 100000:
                                self.drainages[cost[0].row][cost[0].col] = letters[index]
                        index += 1
        return "\n" + "\n".join([" ".join(row) for row in self.drainages])
    
    def __repr__(self):
        return "Problem B Case %d" % self.caseNum

class Contents:
    def __init__(self, f):
        self.data = [line.strip() for line in f]
        self.i = 0

    def read(self):
        return self.readList(1)[0]

    def readList(self, len):
        result = self.data[self.i : self.i + len]
        self.i += len
        return result

def run():
    import sys
    f = file(sys.argv[1])
    s = Contents(f)
    numCases = int(s.read())
    
    for caseNum in range(numCases):
        case = Case(s, caseNum)
        print "Case #%d:%s" % (caseNum + 1, case.solve())
        sys.stdout.flush()
        
if __name__ == "__main__":
    run()