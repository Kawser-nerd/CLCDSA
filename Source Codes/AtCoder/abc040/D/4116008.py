def main():
    n, m = map(int, input().split())
    edges = [tuple(map(int, input().split())) for _ in range(m)]
    edges.sort(key=lambda x:-x[2])
    q = int(input())
    queries = [tuple(map(int, input().split())) + (i,) for i in range(q)]
    queries.sort(key=lambda x:-x[1])
    answers = [None] * q
    
    parent = [i for i in range(n)]
    unionSize = [1 for _ in range(n)]
    def find(x):
        if x == parent[x]: return x
        parent[x] = find(parent[x])
        return parent[x]
    
    def unite(x, y):
        px, py = find(x), find(y)
        if px != py:
            parent[px] = py
            unionSize[py] += unionSize[px]
    
    index = 0
    for v, w, i in queries:
        while index < m and edges[index][2] > w:
            unite(edges[index][0] - 1, edges[index][1] - 1)
            index += 1
        answers[i] = unionSize[find(v - 1)]
    
    print(*answers, sep="\n")    

main()