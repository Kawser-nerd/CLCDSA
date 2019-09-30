import psyco
psyco.full()

class Node():
    def __init__(self, empt, Q, g):
        self.empt = empt
        self.Q = Q
        self.g = g

#return a negative integer if self < other, zero if self == other, a positive integer if self > other
    def __cmp__(self, other):
        return self.g - other.g
#        return self.f - other.f

    def __repr__(self):
        return str(self.empt)+"-"+str(self.Q)+" "+str(self.g)+"."


def binary_search(arr, x, lo=0, hi=None):
    if hi is None:
        hi = len(arr)
    while lo < hi:
        mid = (lo+hi)//2
        midval = arr[mid]
        if midval < x:
            lo = mid+1
        elif midval > x:
            hi = mid
        else:
            return mid
    return lo


import heapq

def solve(P, Q):
    root=Node([0,P+1], Q,  0)
    open = [root]
    while len(open)>0:
        node = heapq.heappop(open)
        empt, Q, g = node.empt, node.Q, node.g
        #print "popped", node

        if Q == []: #goal
            return g

        for i in range(len(Q)): #pick prisoner i first
            rel=Q[i]
            #release him into te
            te = [e for e in empt]
            ind=binary_search(te, rel)
            te.insert(ind, rel)
            heapq.heappush(open, Node(te, Q[:i]+Q[i+1:], g+te[ind+1] - te[ind-1] - 2))

        #print node, " -> open=", open

    print "shit"
    return -1

from time import time
if __name__ == "__main__":
    def getInts():
        return map(int, data.readline().rstrip('\n').split(' '))
    start_time=time()
    output = open('d:/gcj/output', 'w')
    data = open("d:/gcj/in", "r")
    Cases = int(data.readline())
    for case in range(1, Cases + 1):
        N, = getInts()
        X, Y, Z, VX, VY, VZ = 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
        for _ in range(N):
            x, y, z, vx, vy, vz = getInts()
            X+=x
            Y+=y
            Z+=z
            VX+=vx
            VY+=vy
            VZ+=vz
        X/=N
        Y/=N
        Z/=N
        VX/=N
        VY/=N
        VZ/=N
        vsqr=VX*VX + VY*VY + VZ*VZ
        if vsqr!=0:
            t=-1.0*(X*VX + Y*VY + Z*VZ)/vsqr
        else:
            t=0
        if t<0: #the center of mass is moving away from you
            #print 'away'
            t=0.0
        print "M=", (X, Y, Z), "  V=", (VX, VY, VZ)
        X+= VX*t
        Y+= VY*t
        Z+= VZ*t
        d=(X*X + Y*Y + Z*Z)**0.5;
        
        s="Case #%d: %f %f\n" % (case, d, t)
        print(s)
        output.write(s)
            
    print time()-start_time

    