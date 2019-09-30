import sys

def main():
    sys.setrecursionlimit(1000000) # recursion limit hack
    buf = input()
    N = int(buf)
    a = []
    b = []
    for i in range(N-1):
        buf = input()
        buflist = buf.split()
        a.append(int(buflist[0]) - 1)
        b.append(int(buflist[1]) - 1)
    graph = []
    for i in range(N):
        graph.append([])
    for i in range(N-1):
        graph[a[i]].append(b[i])
        graph[b[i]].append(a[i])
    path = find_path(graph, 0, N-1, [])
    split_point = (len(path) + 1) // 2
    fennec_base = path[0:split_point]
    snuke_base = path[split_point:len(path)]
    fennec_vertex_count = len(fennec_base)
    snuke_vertex_count = len(snuke_base)
    for i, v in enumerate(fennec_base):
        for j in graph[v]:
            if i != 0:
                if j == fennec_base[i-1]:
                    continue
            if i != len(fennec_base) - 1:
                if j == fennec_base[i+1]:
                    continue
            else:
                if j == snuke_base[0]:
                    continue
            fennec_vertex_count += get_vertex_count(graph, v, j)
    for i, v in enumerate(snuke_base):
        for j in graph[v]:
            if i != 0:
                if j == snuke_base[i-1]:
                    continue
            else:
                if j == fennec_base[-1]:
                    continue
            if i != len(snuke_base) - 1:
                if j == snuke_base[i+1]:
                    continue
            snuke_vertex_count += get_vertex_count(graph, v, j)
    if fennec_vertex_count > snuke_vertex_count:
        print("Fennec")
    else:
        print("Snuke")

def find_path(graph, current, target, path):
    path.append(current)
    if current == target:
        return path
    for i in graph[current]:
        if len(path) >= 2:
            if i == path[-2]:
                continue
        result = find_path(graph, i, target, path)
        if result:
            return path
    path.pop()
    return None

def get_vertex_count(graph, base, next):
    count = 1
    for i in graph[next]:
        if i == base:
            continue
        count += get_vertex_count(graph, next, i)
    return count

if __name__ == '__main__':
    main()