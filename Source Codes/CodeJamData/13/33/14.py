
from Queue import PriorityQueue
    
class Tribe:
    def __init__(self, d, n, w, e, s, delta_d, delta_p, delta_s):
        self.d = d
        self.n = n
        self.w = w
        self.e = e
        self.s = s
        self.delta_d = delta_d
        self.delta_p = delta_p
        self.delta_s = delta_s
    def evolve(self):
        self.d += self.delta_d
        self.w += self.delta_p
        self.e += self.delta_p
        self.s += self.delta_s
        self.n -= 1
    def __lt__(self, other):
        return self.d < other.d

for t in range(1, int(raw_input()) + 1):
    print "Case #"+str(t)+":",
    N = int(raw_input())
    Q = PriorityQueue()
    current_day = -1
    old_wall = [0]*1000
    new_wall = [0]*1000
    offset = 500
    successfulAttacks = 0
    for n in range(N):
        d, n, w, e, s, delta_d, delta_p, delta_s = [int(x) for x in raw_input().split()]
        Q.put(Tribe(d,n,w,e,s,delta_d,delta_p,delta_s))
    while not Q.empty():
        current = Q.get()
        failed = False
        if current_day != current.d:
            old_wall = [x for x in new_wall]
            current_day = current.d
        for i in range(current.w + offset,current.e + offset):
            if old_wall[i] < current.s:
                new_wall[i] = max(new_wall[i], current.s)
                failed = True
        if failed:
            successfulAttacks += 1
        current.evolve()
        if current.n >0:
            Q.put(current)
    print successfulAttacks
              
        
