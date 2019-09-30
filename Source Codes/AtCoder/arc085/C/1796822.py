#  --*-coding:utf-8-*--

INF = float('inf');

def fulkerson(graph, src, sink):
    n = len(graph)

    matrix = [[0]*n for i in range(n)]
    bothDirGraph = [[] for i in range(n)]

    for nodeId, edges in enumerate(graph):
        for nodeId2, flowLimit in edges:
            matrix[nodeId][nodeId2] = flowLimit
            bothDirGraph[nodeId].append(nodeId2)
            bothDirGraph[nodeId2].append(nodeId)

    while True:
        path = findPath(bothDirGraph, matrix, src, sink)

        if path == None:
            break

        v = min(matrix[path[i]][path[i+1]] 
                for i in range(len(path)-1))

        for i in range(len(path)-1):
            node1 = path[i]
            node2 = path[i+1]
            
            matrix[node1][node2] -= v
            matrix[node2][node1] += v

    return (sum(c for _, c in graph[src]) - 
            sum(c for c in matrix[src]))


def findPath(bothDirGraph, matrix, src, sink):
    prevs = [None]*len(matrix)
    q = set([src])
    prevs[src] = src

    while len(q) > 0:
        node = q.pop()

        for nextNode in bothDirGraph[node]:
            if prevs[nextNode] == None and matrix[node][nextNode] > 0:
                prevs[nextNode] = node
                
                if nextNode == sink:
                    path = []
                    pathNode = sink

                    while pathNode != src:
                        path.append(pathNode)
                        pathNode = prevs[pathNode]

                    path.append(src)
                    return list(reversed(path))

                q.add(nextNode)

    return None
                    
def f(N, A):
    graph = [[] for i in range(N+2)]
    srcId = 0
    dstId = N+1

    for nodeId, a in enumerate(A, 1):
        if a < 0:
            graph[0].append((nodeId, -a))
        else:
            graph[nodeId].append((N+1, a))

        for k in range(2, N//nodeId+1):
            graph[nodeId].append((nodeId*k, INF))

    return (sum(filter(lambda a: a>0, A)) - 
            fulkerson(graph, 0, N+1))

def main():
    N = int(input())
    A = list(map(int, input().split()))

    print(f(N, A))

if __name__ == '__main__':
    main()