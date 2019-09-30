from sys import stdin, stderr
from Queue import PriorityQueue

def interval_dist(a0, a1, b0, b1):
    assert a0 <= a1 and b0 <= b1
    if a1 < b0:
        return b0-a1
    elif b1 < a0:
        return a0-b1
    else:
        return 0

def distance(b1, b2):
    dx = interval_dist(b1[0], b1[2], b2[0], b2[2])
    dy = interval_dist(b1[1], b1[3], b2[1], b2[3])
    return max(dx, dy) - 1

T = int(stdin.readline())
for t in range(1,T+1):
    W, H, B = [int(word) for word in stdin.readline().strip().split()]

    left_bank = (-1,0,-1,H-1)
    right_bank = (W,0,W,H-1)

    BB = set([left_bank, right_bank])
    for ln in range(B):
        BB.add(tuple([int(word) for word in stdin.readline().strip().split()]))

    dist = dict()
    dist[left_bank] = 0
    Q = PriorityQueue()
    Q.put((0, left_bank))

    while right_bank in BB:
        dst, b = Q.get()
        print >>stderr, BB
        print >>stderr, dist
        print >>stderr

        if b in BB:
            BB.remove(b)

            for b2 in BB:
                dst2 = dst + distance(b, b2)
                
                if b2 not in dist or dst2 < dist[b2]:
                    dist[b2] = dst2
                    Q.put( (dst2, b2) )

    print "Case #"+str(t)+":",dist[right_bank]
