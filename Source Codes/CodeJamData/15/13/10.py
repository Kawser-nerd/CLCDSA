import sys
import math
sys.stdin = open('a.in', 'r')
sys.stdout = open('a.out', 'w')

ans = []
n = 0


def getline():
    return [int(c) for c in input().split()]

def same(q, u):
    t = 0
    for v in q:
        if v[0]*u[0]+v[1]*u[1]>=0:
            t += 1
    return t

def calc(q, n):
    ma = 0
    q.sort()
    pi = 3.14159265359
    eps = 0.0000000001
    p = q + [c+2*pi for c in q]
    #print(p)
    j = 0
    for i in range(n-1):
        while j+1<len(p) and p[j+1]-p[i]<pi+eps:
            j += 1
        if j == len(p):
            return 0
        ma = max(ma, j-i+1)

    return max(0, n-1-ma)

def solve():
    global ans
    global n
    pi = 3.14159265359
    [n] = getline()
    ans = [0 for i in range(n)]
    p = []
    for i in range(n):
        p.append(getline())
    if n <= 3:
        return
    for i in range(n):
        q = []
        for j in range(n):
            if i!=j:
                x = p[j][0]-p[i][0]
                y = p[j][1]-p[i][1]
                tmp = math.atan2(y, x)
                if tmp<0: tmp += 2*pi
                q.append(tmp)
        #print(q)
        ans[i] = calc(q, n)


for T in range(int(input())):
    sys.stderr.write(str(T))
    print('Case #%d:' % (T+1))
    solve()
    for i in range(n):
        print(ans[i])