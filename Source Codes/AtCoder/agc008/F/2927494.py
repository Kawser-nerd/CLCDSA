import sys
import json
import itertools

INFINITY = 100000000

def parse_data(input_string):
    INF = INFINITY

    first_nl = input_string.index('\n')
    n = int(input_string[:first_nl])
    fav_pattern = [int(s) * INF for s in input_string[-n - 1:-1]]

    edges = json.loads("[" + input_string[first_nl + 1:-n - 2].replace(" ", ",").replace("\n", ",") + "]")
    graph = [[] for _ in range(n)]
    graph[0].append(None)
    for i in range(0, (n - 1) * 2, 2):
        a = edges[i] - 1
        b = edges[i + 1] - 1
        graph[a].append(b)
        graph[b].append(a)
    return (n, fav_pattern, graph)

def solve():
    INF = INFINITY

    n, fav_count, graph = parse_data(sys.stdin.read())
    height1 = [0] * n
    height2 = [0] * n
    dfs_order = []

    stack = [None, 0, 0]
    while True:
        node = stack[-1]
        index = stack[-2]
        if index < len(graph[node]):
            dtr = graph[node][index]
            stack[-2] += 1
            if dtr != stack[-3]:
                stack.extend((0, dtr))
                dfs_order.append(dtr)
            else:
                graph[node][0], graph[node][index] = dtr, graph[node][0]
        else:
            del stack[-2:]
            if len(stack) <= 1: break
            parent = stack[-1]
            dtr_height = height1[node] + 1
            if dtr_height >= height1[parent]:
                height1[parent], height2[parent] = dtr_height, height1[parent]
            elif dtr_height > height2[parent]:
                height2[parent] = dtr_height
            if fav_count[node] != 0:
                fav_count[parent] += 1

    answer = 0
    if fav_count[0] >= INF:
        lb = -1
    else:
        lb = min((height1[dtr] for dtr in graph[0][1:] if fav_count[dtr] != 0), default=INF)
    ub = height2[0]
    if ub > lb:
        answer += ub - lb
    for node in dfs_order:
        parent = graph[node][0]
        has_fav_below = (fav_count[node] != 0)
        has_fav_above = fav_count[parent] > has_fav_below
        fav_count[node] += has_fav_above
        node_height = height1[node]
        if node_height + 1 == height1[parent]:
            lb = height2[parent]
            if lb <= node_height and has_fav_above:
                answer += 1
            elif lb >= node_height and has_fav_below:
                answer += 1

            parent_height = lb + 1
            if parent_height >= node_height:
                height1[node], height2[node] = parent_height, node_height
            elif parent_height > height2[node]:
                height2[node] = parent_height
        else:
            answer += has_fav_below
            lb = height1[parent]
            height1[node], height2[node] = lb + 1, node_height
        if fav_count[node] >= INF:
            lb = -1
        else:
            if not has_fav_above: lb = INF
            for dtr in itertools.islice(graph[node], 1, None):
                if fav_count[dtr] != 0:
                    lb = min(height1[dtr], lb)
        ub = height2[node]
        if ub > lb:
            answer += ub - lb

    print(answer)

solve()