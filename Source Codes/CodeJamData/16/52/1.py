
from __future__ import division, print_function
from random import *
input = raw_input
def sh(deps, s, l):
    while len(s) > 0:
        w = sample(s, 1)
        w = w[0]
        while deps[w] - 1 in s:
            w = deps[w] - 1
        l.append(w)
        s.remove(w)
        #s.update(children[w])

K = 10000

t = int(input())
for i in range(t):
    print("Case #%d:" % (i + 1), end = " ")
    n = int(input())
    dep = list(map(int, input().split()))
    cars = input().strip()
    m = int(input())
    cool = list(input().split())
    childs = [[] for i in range(n)]
    base = []
    for i in range(n):
        if dep[i] != 0:
            childs[dep[i] - 1].append(i)
        else:
            base.append(i)
    nums = [0] * m
    for i in range(K):
        r = []
        #sh(childs, set(base), r)
        sh(dep, set(range(n)), r)
        w = "".join(cars[i] for i in r)
        for j in range(m):
            if cool[j] in w:
                nums[j] += 1
    freqs = [u / K for u in nums]
    print(" ".join(map(str, freqs)))
        
