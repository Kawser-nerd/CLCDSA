import sys

global D,I,M,N,A,DP

def mincost(at,prev):
    if (at,prev) in DP:
        return DP[(at,prev)]
    if at == N:
        return 0
    cost = mincost(at+1,prev)+D
    for i in range(256):
        if abs(i-prev) <= M or prev == -1:
            cost = min(cost,mincost(at+1,i) + abs(i-A[at]))
        if abs(i-A[at]) < abs(A[at]-prev) and (prev == -1 or abs(i-prev) <= M):
            cost = min(cost,mincost(at,i)+I)
    DP[(at,prev)] = cost
#    print "(%d,%d) = %d"%(at,prev,cost)
    return cost

T = int(sys.stdin.readline())
for t in range(T):
    s = sys.stdin.readline().split()
    D = int(s[0])
    I = int(s[1])
    M = int(s[2])
    N = int(s[3])
    A = []
    s = sys.stdin.readline().split()
    for i in range(N):
        A.append(int(s[i]))
    DP = {}
    print "Case #%d: %d"%(t+1,mincost(0,-1))