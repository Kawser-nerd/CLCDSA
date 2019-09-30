#!/usr/bin/env python
import sys
from collections import *

def solve():
    # a = sys.stdin.readline().split()
    # print a
    data = map(int, sys.stdin.readline().split())[1:]
    if not data:
        return 0

    c = Counter(data)
    q = deque()

    BIG = 2000
    ret = BIG

    it = sorted(c.iteritems())
    it.append([it[-1][0]+1, 0])
    # print "##", it
    i_ = it[0][0]-1
    for i,n in it:
        if i!=i_+1:
            ret = min(ret, min([i_+1-j for j in q]))
            q.clear()
        while n > len(q):
            q.append(i)
        while len(q)>n:
            ret = min(ret, i - q.popleft())
        i_ = i

    return ret



if __name__=="__main__":
    T = int(sys.stdin.readline())
    for t in range(T):
        print "Case #{}: {}".format(t+1, solve())

    
