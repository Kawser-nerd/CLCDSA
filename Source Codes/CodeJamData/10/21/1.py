#!/usr/bin/env python

root = {}

def add_dir(path):
    parts = path[1:].split('/')
    node = root
    ans = 0
    for i in parts:
        if i not in node:
            ans += 1
            node[i] = {}
        node = node[i]
    return ans

T = int(raw_input())
for case in xrange(1, T + 1):
    root = {}
    N, M = [int(x) for x in raw_input().split()]
    for i in xrange(N):
        add_dir(raw_input().strip())
    ans = 0
    for i in xrange(M):
        ans += add_dir(raw_input().strip())
    print 'Case #%d: %d' % (case, ans)
