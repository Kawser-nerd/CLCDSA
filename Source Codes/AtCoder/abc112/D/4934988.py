import bisect
import math
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
if M % N == 0:
    print(M//N)
else:
    upper = math.ceil(M/N)
    factor = set()
    for i in range(1, int(M**0.5)+1):
        if M % i == 0:
            factor.add(i)
    
    factor1 = set()
    for i in factor:
        factor1.add(M//i)
    factor |= factor1
    
    factor = sorted(list(factor))
    print(factor[bisect.bisect_right(factor, upper)-1])