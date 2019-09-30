#!/usr/bin/python2
# -*- coding: utf-8 -*-

import sys

def rl(proc=None):
    if proc is not None:
        return proc(sys.stdin.readline())
    else:
        return sys.stdin.readline().rstrip()

def srl(proc=None):
    if proc is not None:
        return map(proc, rl().split())
    else:
        return rl().split()

def mk(pat, c):
    return pat * c + pat[0]

def mmax(A, last):
    ret = [-1, ""]
    for t in A:
        if t[1] != last and t[0] > ret[0]:
            ret = t
    return ret

def solve(N, R, ry, Y, yb, B, rb):
    if R + yb == N:
        if R != yb:
            return "IMPOSSIBLE"
        return "RG" * R
    if Y + rb == N:
        if Y != rb:
            return "IMPOSSIBLE"
        return "YV" * Y
    if B + ry == N:
        if B != ry:
            return "IMPOSSIBLE"
        return "BO" * B
    if yb and R <= yb or rb and Y <= rb or ry and B <= ry:
        return "IMPOSSIBLE"
    rep = []
    R -= yb
    rep.append(("R", mk("RG", yb)))
    Y -= rb
    rep.append(("Y", mk("YV", rb)))
    B -= ry
    rep.append(("B", mk("BO", ry)))

    A = [[R, "R"], [Y, "Y"], [B, "B"]]
    A.sort(reverse=True)

    ret = []
    mx = mmax(A, "")
    while mx[0]:
        last = mx[1]
        ret.append(last)
        mx[0] -= 1
        mx = mmax(A, last)

    if max(A)[0] or ret[-1] == ret[0]:
        return "IMPOSSIBLE"
    ret = "".join(ret)

    for f, t in rep:
        idx = ret.find(f)
        if idx >= 0:
            ret = ret[:idx] + t + ret[idx+1:]

    return ret


def main():
    T = rl(int)
    for t in xrange(1, T+1):
        print "Case #%d: %s" % (t, solve(*srl(int)))

if __name__ == '__main__':
    main()
