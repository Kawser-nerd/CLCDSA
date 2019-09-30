from math import *

def gcd(a,b):
    if b == 0: return a
    return gcd(b,a%b)

def solve(testnum):
    p,q = [int(x) for x in input().split('/')]
    g = gcd(p,q)
    p/=g; q/=g
    if 2**int(round(log2(q))) == q:
        print("Case #%d: %d"%(testnum,ceil(log2(q/p))))
    else:
        print("Case #%d: impossible"%testnum)

for i in range(int(input())): solve(i+1)
