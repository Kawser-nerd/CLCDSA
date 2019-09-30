#!usr/bin/env python3
from collections import defaultdict
import math
def LI(): return list(map(int, input().split()))
def II(): return int(input())
def LS(): return input().split()
def S(): return input()
def IIR(n): return [II() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
mod = 1000000007

#A
"""
a,b = LS()
c = int(a+b)
for i in range(1,1000):
    if i * i == c:
        print("Yes")
        quit()
print("No")
"""

#B
"""
a,b = LI()
if a*b <= 0:
    print("Zero")
else:
    if b < 0:
        if (a-b) %2 == 1:
            print("Positive")
        else:
            print("Negative")
    else:
        print("Positive")
"""

#C
"""
n = II()
s = SR(n)
march = [[] for i in range(5)]
ch = list("MARCH")
for i in s:
    for j in range(5):
        if i[0] == ch[j]:
            march[j].append(i)
ans = 0
for i in range(5):
    for j in range(i):
        for k in range(j):
            if len(march[i])*len(march[j])*len(march[k]) == 0:
                break
            ans += len(march[i])*len(march[j])*len(march[k])
print(ans)
"""

#D
n = II()
d = LIR(n)
q = II()
p = IIR(q)
d.insert(0,[0 for i in range(n+1)])
for i in range(n):
    d[i+1].insert(0,0)
for i in range(n):
    for j in range(n):
        d[i+1][j+1] += d[i+1][j]+d[i][j+1]-d[i][j]
ans = [0 for i in range(n**2+1)]

for a in range(n+1):
    for b in range(n+1):
        for c in range(a):
            for e in range(b):
                ans[(a-c)*(b-e)] = max(ans[(a-c)*(b-e)],d[a][b]-d[c][b]-d[a][e]+d[c][e])

for i in p:
    an = 0
    for a in range(i+1):
        an = max(an, ans[a])
    print(an)

#E

#F

#G

#H

#I

#J

#K

#L

#M

#N

#O

#P

#Q

#R

#S

#T