import math

def solve(ensui,a,b):
    V = 0
    for e in ensui:
        if e[0]<a:
            if e[0]+e[2]<a:
                continue
            elif e[0]+e[2]<b:
                V += solveV((e[0]+e[2]-a)/e[2]*e[1],e[0]+e[2]-a)
            else:
                V += solveV((e[0]+e[2]-a)/e[2]*e[1],e[0]+e[2]-a) - solveV((e[0]+e[2]-b)/e[2]*e[1],e[0]+e[2]-b)
        elif e[0]<b:
            if e[0]+e[2]<b:
                V += solveV(e[1],e[2])
            else:
                V += solveV(e[1],e[2]) - solveV((e[0]+e[2]-b)/e[2]*e[1],e[0]+e[2]-b)
        else:
            continue
    return V

def solveV(r,h):
    return 1/3 * math.pi * r * r * h

N,Q = map(int, input().split())
ensui = []
A = []
B = []
for _ in range(N):
    x,r,h = map(int, input().split())
    ensui.append((x,r,h))
O = []
for _ in range(Q):
    a,b = map(int, input().split())
    O.append(solve(ensui,a,b))
for o in O:
    print(o)