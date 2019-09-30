T = 10002

def check(c,m):
    for x in xrange(T):
        if not c[x]: continue
        for i in xrange(m):
            if x+i>=T or not c[x+i]: return False
            c[x+i]-=1
    return True

def solve():
    a = map(int,raw_input().split())
    n = a[0]
    a = a[1:]
    l,r = 0,n+1
    b = [0]*T
    for x in a: b[x]+=1
    q = []
    if n ==0: return 0
    m = 10**10
    for i in xrange(1,T):
        for j in xrange(b[i-1]-b[i]):
            m=min(m,i-q.pop(0))
        for j in xrange(b[i]-b[i-1]):
            q.append(i)
    return m

t = input()
for i in xrange(t):
    print "Case #%d: %d"%(i+1,solve())
