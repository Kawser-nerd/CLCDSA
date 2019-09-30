import operator
import itertools
import functools
import math

def solve(a, A, b, B):
    if len(A) == 0 or len(B) == 0:
        return 0
    if (sum(a), sum(b)) in cache:
        return cache[(sum(a), sum(b))]
    if A[0] != B[0]:
        r1 = solve(a[1:], A[1:], b, B)
        r2 = solve(a, A, b[1:], B[1:])
        cache[(sum(a), sum(b))] =  max((r1, r2))
        return max((r1, r2))
    else:
        if a[0] > b[0]:
            r = solve([a[0]-b[0]] + a[1:], A, b[1:], B[1:]) + b[0]
        elif a[0] < b[0]:
            r = solve(a[1:], A[1:], [b[0]-a[0]] + b[1:], B) + a[0]
        else:
            r = solve(a[1:], A[1:], b[1:], B[1:]) + a[0]
        cache[(sum(a), sum(b))] = r
        return r
     
fn = open('1.in')
ofn = open('1.out', 'w')
TC = int(fn.readline())
for tc in range(TC):
    N, M = map(int, fn.readline().strip().split())
    r = map(int, fn.readline().strip().split())
    a = [r[2*j] for j in range(N)]
    A = [r[2*j+1] for j in range(N)]
    r = map(int, fn.readline().strip().split())
    b = [r[2*j] for j in range(M)]
    B = [r[2*j+1] for j in range(M)]
    cache = {}
    #print A, a
    #print B, b
    res = solve(a, A, b, B)
    print tc       
    print >>ofn, 'Case #{}: {}'.format(tc +1, res)
        
        
