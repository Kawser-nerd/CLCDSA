from functools import reduce
from fractions import gcd
N,K=map(int,input().split())
A=sorted(map(int,input().split()))
M=reduce(gcd,A)
if K<=A[-1] and K%M==0:print("POSSIBLE")
else:print("IMPOSSIBLE")