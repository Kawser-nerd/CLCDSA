#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: solve.py
# $Date: Sat Apr 16 10:08:09 2016 +0800
# $Author: jiakai <jia.kai66@gmail.com>

def find_circ_len(bnext):
    circ = [0] * len(bnext)
    visited = [0] * len(bnext)
    vis_id = 0
    for i in range(len(bnext)):
        if visited[i]:
            continue

        j = i
        vis_id += 1
        while True:
            j = bnext[j]
            if visited[j]:
                break
            visited[j] = vis_id

        if visited[j] != vis_id:
            continue

        clen = 0
        src = j
        t = src
        while True:
            t = bnext[t]
            clen += 1
            if t == src:
                break

        t = src
        while True:
            circ[t] = clen
            t = bnext[t]
            if t == src:
                break
    return circ


class TGroup:
    def __init__(self, id, s):
        self.size = s
        self.id = id

class TCircle:
    def __init__(self, s):
        self.size = s

def solve(bnext):
    bnext = [i - 1 for i in bnext]

    circ = find_circ_len(bnext)

    vtx2type = [None] * len(bnext)
    def get_type(src):
        if not vtx2type[src]:
            vtx2type[src] = do_get_type(src)
        return vtx2type[src]

    def do_get_type(src):
        if circ[src] == 2:
            return TGroup(src, 0)
        if not circ[src]:
            t = get_type(bnext[src])
            if type(t) is TGroup:
                return TGroup(t.id, t.size + 1)
            assert type(t) is TCircle
            return t

        assert circ[src] > 2
        return TCircle(circ[src])

    grp_size = [0] * len(bnext)
    max_circ = 0
    for i in range(len(bnext)):
        t = get_type(i)
        if type(t) is TGroup:
            grp_size[t.id] = max(grp_size[t.id], t.size)
        else:
            max_circ = max(max_circ, t.size)

    grp_base = 0
    for i in circ:
        if i == 2:
            grp_base += 1
    return max(max_circ, sum(grp_size) + grp_base)


def main():
    nr_case = int(input())
    for case in range(nr_case):
        N = int(input())
        bmap = list(map(int, input().split()))
        assert len(bmap) == N
        print('Case #{}: {}'.format(case + 1, solve(bmap)))

if __name__ == '__main__':
    main()




