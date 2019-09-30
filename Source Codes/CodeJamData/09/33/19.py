from sys import stdin

# def solve(Q,S,E):
#     #Assumption the optimal strategy is to relese the guy most in the middle first
#     if len(Q) == 0: return 0
#     b,bd=-1,E-S+10
#     #This could be done with a binary search
#     for p in Q:
#         d = max(E-p,p-S)
#         if d < bd:
#             bd = d
#             b = p
#     L,R=[],[]
#     for p in Q:
#         if p < b: L.append(p)
#         elif p > b: R.append(p)
#     print b,
#     return solve(L,S,b-1) + solve(R,b+1,E) + (E-S)

def solvebf(Q,S,E):
    if len(Q) == 0: return 0
    b = Ellipsis
    for p in Q:
        L,R=[],[]
        for q in Q:
            if q < p: L.append(q)
            elif q > p: R.append(q)
        b = min(b,solvebf(L,S,p-1) + solvebf(R,p+1,E))
    return b + (E-S)

N = int(stdin.readline().strip())
for n in xrange(N):
    P, _ = map(int,stdin.readline().split())
    Q = map(int,stdin.readline().split())
    print "Case #%d: %d"%(n+1,solvebf(Q,1,P))
    
