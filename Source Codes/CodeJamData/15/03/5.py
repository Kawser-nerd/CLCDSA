import sys

m =[[0, 0, 0, 0, 0],
    [0, 1, 2, 3, 4],
    [0, 2,-1, 4,-3],
    [0, 3,-4,-1, 2],
    [0, 4, 3,-2,-1]]
c = " 1ijk"

def sign(a):
    return 1 if a >= 0 else -1

def mul(a,b):
    return sign(a)*sign(b)*m[abs(a)][abs(b)]

def char2int(ch):
    return c.find(ch)

def is_dijkstra(s):
    p = 1
    goal = 2
    for ch in s:
        p = mul(p, char2int(ch))
        if p == goal:
            goal += 1
            p = 1
    return goal == 5 and p == 1

T = int(sys.stdin.readline())
for t in range(T):
    L,X = map(int, sys.stdin.readline().split())
    S = sys.stdin.readline().strip()
    if X < 8:
        S *= X
    else:
        S *= 8 + (X % 4)
    print "Case #%d: %s" % (t+1, "YES" if is_dijkstra(S) else "NO")
