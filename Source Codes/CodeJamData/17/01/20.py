import sys

def go(M):
    S,K = M.split()
    K = int(K)
    n = len(S)
    S = [c=='+' for c in S] # True if happy
    t = 0
    for i in range(n-K+1):
        # Flipping i to i+K-1
        # Need i+K-1<n
        # i<n-K+1
        if not S[i]:
            t += 1
            for j in range(i,i+K):
                S[j] ^= 1
    for i in range(n-K+1,n):
        if not S[i]:
            return 'IMPOSSIBLE'
    return t
    

#sys.stdin=open('dataa.txt')

T=input()
for t in range(1,T+1):
    M=raw_input()
    print "Case #{}: {}".format(t,go(M))
