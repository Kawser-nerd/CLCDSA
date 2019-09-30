#!/usr/bin/env python3

class Node:
    parent = None
    children = set()
    count = None

def main():
    n, x = map(int, input().split())
    hn = list(map(int, input().split()))
    ab = []
    for i in range(n - 1):
        a, b = map(int, input().split())
        ab.append((a - 1, b - 1))

    nodes = [Node() for i in range(n)]
    dfs_make_tree(x - 1, None, n, ab, nodes)
    dfs_count(x - 1, nodes, hn)
    print(max(0, (count_nonzero_branches(nodes) - 1)) * 2)

def dfs_make_tree(my_id, parent_id, n, ab, nodes):
    assert my_id != parent_id
    node = nodes[my_id]
    node.parent = parent_id
    adjs = set()
    for edge in ab:
        if my_id == edge[0]:
            adjs.add(edge[1])
        elif my_id == edge[1]:
            adjs.add(edge[0])
    adjs -= {parent_id}
    node.children = adjs
    for c in node.children:
        dfs_make_tree(c, my_id, n, ab, nodes)

def dfs_count(my_id, nodes, hn):
    node = nodes[my_id]
    node.count = hn[my_id]
    for c in node.children:
        node.count += dfs_count(c, nodes, hn)
    return node.count

def count_nonzero_branches(nodes):
    cnt = 0
    for nd in nodes:
        if nd.count > 0:
            cnt += 1
    return cnt

main()