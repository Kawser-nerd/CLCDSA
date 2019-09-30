#! /usr/bin/env python

import sys
fin = open(sys.argv[1], "r")
fout = open("p4.out", "w")

mod = 1000000007

def maxpref(s1, s2):
    for i in xrange(min(len(s1), len(s2))):
        if s1[i] != s2[i]:
            return i

    return min(len(s1), len(s2))

def maxi(l):
    if l == []:
        return 0
    else:
        return max(l)

def index_min(values):
    return min(xrange(len(values)),key=values.__getitem__)


T = int(fin.readline())
for i in xrange(T):
    M, N = map(int, fin.readline().split())
    S = ["" for j in xrange(M)]

    for j in xrange(M):
        S[j] = fin.readline()[:-1]

    d = [[0 for j in xrange(M)] for k in xrange(M)]
    for j in xrange(M):
        for k in xrange(M):
            d[j][k] = maxpref(S[j], S[k]) + 1

    cds = [[] for j in xrange(N)]

    ans = 0
    
    def find_num(j, count):
        if j == M:
            if count == ans:
                return 1
            else:
                return 0
        total = 0
        dists = map(lambda x: maxi(map(lambda y: d[j][y], x)), cds)
        for k in xrange(len(dists)):
            cds[k].append(j)
            total += find_num(j+1, count + len(S[j]) + 1 - dists[k])
            total %= mod
            cds[k].pop()

        return total

    for j in xrange(M):
        dists = map(lambda x: maxi(map(lambda y: d[j][y], x)), cds)
        cd = index_min(dists)
        cds[cd].append(j)
        
        md = dists[cd]

        ans += len(S[j]) + 1 - md

    cds = [[] for j in xrange(N)]
    num = find_num(0, 0)

    fout.write("Case #" + str(i+1) + ": " + str(ans) + " " + str(num) + "\n")


