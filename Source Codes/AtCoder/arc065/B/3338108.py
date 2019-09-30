#!/usr/bin/env python3

def main():
    n, k, l = map(int, input().split())
    pq = get_edges(k)
    rs = get_edges(l)
    road_groups = get_group(n, pq)
    rail_groups = get_group(n, rs)
    count = {}
    for i in range(n):
        gp = (find(i, road_groups), find(i, rail_groups))
        if gp not in count:
            count[gp] = 1
        else:
            count[gp] += 1
    res = []
    for i in range(n):
        gp = (find(i, road_groups), find(i, rail_groups))
        res.append(count[gp])
    print(" ".join(map(str, res)))

def get_edges(k):
    pq = []
    for i in range(k):
        p1, q1 = map(int, input().split())
        pq.append((p1 - 1, q1 - 1))
    return pq

def get_group(n, edges):
    group = [i for i in range(n)]
    for x, y in edges:
        unite(x, y, group)
    return group

def unite(x, y, parents):
    px = find(x, parents)
    py = find(y, parents)
    parents[py] = px

def find(x, parents):
    if parents[x] == x:
        return x
    fx = find(parents[x], parents)
    parents[x] = fx
    return fx

main()