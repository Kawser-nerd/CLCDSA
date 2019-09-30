def do():
    times = input()
    for i in xrange(times):
        print 'Case #%d:'%(i+1),
        calculate()

import math
from collections import deque

def twice(L):
    for _ in L:
        yield _
    for _ in L:
        yield _

def counter_clock(A,B):
    return A[1]*B[0]-A[0]*B[1] > 0

def calculate():
    L = [tuple(map(int,raw_input().split())) for i in xrange(input())]
    
    print
    
    for I in L:
        angle = []
        
        for I1 in L:
            if I is I1:
                continue
            
            sub = I1[0]-I[0],I1[1]-I[1]
            angle.append((math.atan2(sub[0],sub[1]),I1,sub))
        
        angle.sort()
        q = deque()
        max_len = 0

        for I in twice(angle):
            at,ang,tar = I
            while len(q) > 0:
                if q[0] is I or counter_clock(tar,q[0][2]):
                    q.popleft()
                else:
                    break
            
            q.append(I)
            max_len = max(max_len,len(q))
        
        print len(L) - max_len - 1



if __name__ == '__main__':
    do()

