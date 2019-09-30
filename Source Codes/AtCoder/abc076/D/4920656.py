import sys, collections, bisect, math, itertools
from fractions import gcd 
input = sys.stdin.readline #???????????

n = int(input())
t = [int(i) for i in input().split()]
v = [int(i) for i in input().split()]

maxspeed = [0]*(n+1)
for i in range(n-1,0,-1):
    maxspeed[i] = min(v[i], v[i-1], t[i] + maxspeed[i+1])

#print(t)
#print(v)
#print(maxspeed)

def dist(first,i): # distance,lastspeed
    ti = t[i]
    vi = v[i]
    mi1= maxspeed[i+1]
    ta = vi - first
    tb = vi - mi1
    if ta + tb <= ti:
        c = (first+vi)*ta/2 + vi*(ti-ta-tb) + (mi1+vi)*tb/2
        lastspeed = mi1
    elif mi1 - first > ti:
        c = (first + first + ti)*ti/2
        lastspeed = first + ti
    else:
        a = (mi1+ti-first)/2
        c = (first+first+a)*a/2 + (first+a+mi1)*(ti-a)/2
#        print(a,'a',c,first,(first+first+a)*a/2, (first+a+mi1)*(ti-a)/2)
        lastspeed = mi1
#    print(c)

    return c, lastspeed


ans = 0
firstspeed = 0
for i in range(n):
    d,firstspeed = dist(firstspeed,i)
#    print(d,firstspeed)
    ans += d

print(ans)