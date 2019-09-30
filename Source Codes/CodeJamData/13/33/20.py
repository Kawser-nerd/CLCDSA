#!/usr/bin/python

from collections import defaultdict
import heapq

class Attack(object):
    def __init__(self, d, n, w, e, s, delta_d, delta_p, delta_s):
        self.d = d
        self.n = n
        self.w = w
        self.e = e
        self.s = s
        self.delta_d = delta_d
        self.delta_p = delta_p
        self.delta_s = delta_s
        self.attacked = 0

    def move(self):
        self.n -= 1
        if self.n <= 0:
            return False

        self.d += self.delta_d
        self.w += self.delta_p
        self.e += self.delta_p
        self.s += self.delta_s
        return True

def get():
    n = input()
    wall = defaultdict(int)
    h = []
    for x in xrange(n):
        d, n, w, e, s, delta_d, delta_p, delta_s = map(int, raw_input().strip().split())
        a = Attack(d,n,w,e,s,delta_d,delta_p,delta_s)
        heapq.heappush(h, (d, a))

    def attack(w, e, s):
        #print (w, e, s)
        return any(wall[x] < s for x in xrange(w, e))

    def resolve(attacks):
        for _, a in attacks:
            for x in xrange(a.w, a.e):
                wall[x] = max(wall[x], a.s)

    ret = 0
    while len(h) > 0:
        attacks = [heapq.heappop(h)]
        while len(h) > 0 and h[0][0] == attacks[0][0]:
            attacks.append(heapq.heappop(h))
        for _, a in attacks:
            if attack(a.w, a.e, a.s):
                ret += 1
        resolve(attacks)
        for _, a in attacks:
            if a.move():
                heapq.heappush(h, (a.d, a))
    return ret

n = input()
for x in xrange(n):
    print 'Case #%d: %s' % (x+1, get())
