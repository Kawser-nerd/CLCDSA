from sys import stdin
from sys import stderr

def getInts():
    return tuple(int(z) for z in stdin.readline().split())

def f(R,Y,B):
    x = []
    remainder = [[1,R,'R',0],[1,Y,'Y',1],[1,B,'B',2]]
    for t in xrange(R+Y+B):
        (p,q,r,s) = max(remainder)
        for k in xrange(3):
            remainder[k][0] = 1
        remainder[s][0] = 0
        x.append(r)
        remainder[s][1] -= 1
    remainder = x
    if remainder[0] == remainder[-1]:
        v = remainder[0]
        i = 1
        while i + 1 < R + Y + B and (remainder[i] == v or remainder[i+1] == v):
            i += 1
        if i == R + Y + B - 1:
            print >>stderr, "TROUBLE"
        else:
            remainder = remainder[:(i+1)]+[v]+remainder[(i+1):-1]
    return "".join(remainder)

def fit(answer, i, s, n):
    return answer[:i]+(s*n)+answer[i:]

(T,) = getInts()

for cn in xrange(1,1+T):
    (N, R, O, Y, G, B, V) = getInts()
    R2 = R - G
    Y2 = Y - V
    B2 = B - O
    if ((R2 < 0) or (Y2 < 0) or (B2 < 0) or
        (R2 > Y2 + B2) or (Y2 > R2 + B2) or (B2 > R2 + Y2)):
        answer = "IMPOSSIBLE"
    elif ((R2 == 0) and (Y2 == 0) and (B2 == 0)):
        if G > 0 and V == 0 and O == 0:
            answer = "RG" * G
        elif G == 0 and V > 0 and O == 0:
            answer = "YV" * V
        elif G == 0 and V == 0 and O > 0:
            answer = "BO" * O
        else:
            answer = "IMPOSSIBLE"
    elif (((R2 == 0) and (R != 0)) or
          ((Y2 == 0) and (Y != 0)) or
          ((B2 == 0) and (B != 0))):
        answer = "IMPOSSIBLE"
    else:
        answer = f(R2,Y2,B2)
        if G != 0:
            i = answer.index("R")
            answer = fit(answer, i, "RG", G)
        if V != 0:
            i = answer.index("Y")
            answer = fit(answer, i, "YV", V)
        if O != 0:
            i = answer.index("B")
            answer = fit(answer, i, "BO", O)
    print "Case #{}: {}".format(cn, answer)
