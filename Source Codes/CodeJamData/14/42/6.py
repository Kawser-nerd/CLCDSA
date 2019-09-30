from sys import stdin, stderr
from collections import deque

T = int(stdin.readline())
for t in range(1,T+1):
    (N,) = [int(word) for word in stdin.readline().strip().split()]
    A = [int(word) for word in stdin.readline().strip().split()]
    sA = list(reversed(sorted(A)))

    perm = [ i for value, i in reversed(sorted(zip(A, range(N)))) ]

    newperm = deque()
    tr = 0
    
    for i in range(N):
        left_ct = sum([ perm[j]<perm[i] for j in range(i)])
        if 2*left_ct < i:
            newperm.appendleft(sA[i])
        else:
            newperm.append(sA[i])
        tr += min(left_ct, i-left_ct)
        
    print "Case #"+str(t)+":",tr
    print >>stderr, list(newperm)
