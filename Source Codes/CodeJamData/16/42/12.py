#!/usr/bin/python3
from multiprocessing import Pool
from pprint import pprint
import sys

def calcprob(p):
    prob = {}
    k = len(p)
    assert k%2 == 0
    for j in range(k//2+1):
        prob[(0, j)] = 0
    prob[(0, 0)] = 1
    i = 0
    for pp in p:
        i+=1
        for j in range(k//2+1):
            res = prob[(i-1, j)] * (1-pp)
            if j>0:
                res = res + prob[(i-1, j-1)] * pp
            prob[(i, j)] = res
    return prob[(i, k//2)]

def solve_test(data):
    n, k, p = data
    p = sorted(p)
    ans = -1
    for i in range(k+1): 
        left = i
        right = k-i
        pp = p[:i] + p[n-right:]
        assert len(pp) == k
        prob = calcprob(pp)
        if prob > ans:
            ans = prob
    sys.stderr.write('.')
    return ans

tests = int(input())
data = []
for test in range(tests):
    sys.stderr.write(str(test))
    n, k = map(int, input().split())
    p = list(map(float, input().split()))
    data.append((n, k, p))
    
with Pool(6) as p:
    res = p.map(solve_test, data)
    
for test in range(tests):
    print("Case #%d: %0.8f" % (test+1, res[test]))
    