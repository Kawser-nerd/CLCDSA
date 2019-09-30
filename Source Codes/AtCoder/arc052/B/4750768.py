import sys
input = sys.stdin.readline
pi = 3.1415926535897932384626433832795
n,q = map(int,input().split())

p = [0.0]*(10**5)
for i in range(n):
    x,r,h = map(int,input().split())
    for j in range(h):
        p[x+j] += r**2*pi*((h-j)**3-(h-j-1)**3)/(3*h**2)


ap = [0.0]*(10**5+3)
for i in range(len(p)):
    ap[i+1] = ap[i]+p[i]
for i in range(q):
    a,b = map(int,input().split())
    print(ap[b]-ap[a])