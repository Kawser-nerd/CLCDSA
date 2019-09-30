from collections import *


def solve(J, P,S,K):
    Q=set()
    A=defaultdict(int)
    B=defaultdict(int)
    C=defaultdict(int)
    for j in range(J):
        for p in range(P):
            for s in range(min(S,K)):
                d=(j+p+s)%S
                Q.add((j,p,d))
                A[(j, p)] += 1
                B[(p,d)] += 1
                C[(d,j)] += 1
    assert(max(A.values()) <= K)
    assert(max(B.values()) <= K)
    assert(max(C.values()) <= K)
    assert(len(Q) == J*P*min(S,K))
    return Q

def test():
    for k in range(1,11):
        for s in range(1,11):
            for p in range(1,s+1):
                for j in range(1,p+1):
                    solve(j, p ,s,k)

T=int(input())
for t in range(T):
    J,P,S,K=map(int,input().split())
    Q=solve(J,P,S,K)
    print("Case #%d: %d" % (t+1, len(Q)))
    for q in Q:
        print(q[0]+1,q[1]+1,q[2]+1)

