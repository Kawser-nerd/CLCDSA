from fractions import Fraction
import sys
sys.setrecursionlimit(1000*100)
#c=int(input())
#a,b=tuple(map(int,input().split()))
#edges=dict((i,[]) for i in range(1,c+1))
#children=filter(lambda x: x != p, edges[r])
#cs.sort(key=lambda x:Fraction(x[0],x[1]),reverse=True)
#if dp[r] is not None:

N=int(input())
S=input()
r=0
g=0
b=0
for s in S:
    if s=='R':
        r^=1
    elif s=='G':
        g^=1
    else:
        b^=1

print(r+g+b)