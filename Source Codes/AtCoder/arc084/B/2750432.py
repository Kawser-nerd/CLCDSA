#!/usr/bin/python3
# -*- coding: utf-8 -*-

from queue import *


class Edge(object):
    def __init__(self, dst, len_):
        self.dst = dst
        self.len = len_


MAX_K = int(1e5 + 5)
INF = int(1e9)

K = 0
dis = [INF for i in range(0, MAX_K)]
vis = [False for i in range(0, MAX_K)]
edge = [[] for i in range(0, MAX_K)]
q = PriorityQueue()


def add(s, t, d):
    edge[s].append(Edge(t, d))


def build():
    for i in range(1, K):
        add(i, i * 10 % K, 0)
        add(i, (i + 1) % K, 1)


def dij(s):
    dis[s] = 0
    q.put((0, s))
    while not q.empty():
        x = q.get()[1]
        if vis[x]:
            continue
        vis[x] = True
        for e in edge[x]:
            if dis[e.dst] > dis[x] + e.len:
                dis[e.dst] = dis[x] + e.len
                q.put((dis[e.dst], e.dst))


if __name__ == "__main__":
    K = int(input())
    build()
    dij(1)
    print(dis[0] + 1)