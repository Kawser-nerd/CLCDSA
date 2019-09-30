import sys

def bellman_ford(n, edges, source):
    """Bellman Ford algorithm

    n: int, the number of nodes.
    edges: list, [edge1, edge2, ... ]
           edge_i = [node, neighbour, weight of the edge]
    source: int, start node.
    """
    # Initializing the distance from source.
    inf = float('inf')
    dist=[inf for i in range(n)]
    dist[source] = 0

    # Relaxation step
    for i in range(n):
        for edge in edges:
            if dist[edge[1]] > dist[edge[0]] + edge[2]:
                dist[edge[1]] = dist[edge[0]] + edge[2]
                if i == n - 1 and edge[1] == n-1:
                    return -1

    return dist


def main():
    input = sys.stdin.readline
    N, M = map(int, input().split())
    edges = []
    for _ in range(M):
        a, b, c = map(int, input().split())
        edges.append((a-1, b-1, -c))

    dist = bellman_ford(N, edges, 0)

    if dist == -1:
        return 'inf'
    else:
        return int(-dist[N-1])


if __name__ == '__main__':
    print(main())