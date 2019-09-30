
import psyco
psyco.full()
import sys
class T:
    def __init__(self, done, switch, distance):
        self.done = done
        self.switch = switch
        self._cost = switch + distance
        #print self
    def cost(self):
        return self._cost
    def __repr__(self):
        return 'T<%d,%d,%d>'%(self.done, self.switch, self._cost)
def main():
    f = sys.stdin
    N = int(f.readline())
    for i in range(N):
        S = int(f.readline())
        names = []
        for j in range(S):
            names.append(f.readline().strip())
        Q = int(f.readline())
        queries = []
        for j in range(Q):
            q = f.readline().strip()
            queries.append(names.index(q))
        todo = [ T(0, 0, 1) ]
        if Q==0:
            R = 0
        else:
            go_on = True
            while go_on:
              try:
                t = todo.pop()
                #print '>', t
                for n in range(S):
                    q = t.done
                    if queries[q]!=n:
                        while q<Q and queries[q]!=n:
                            q += 1
                        if q==Q:
                            R = t.switch
                            go_on = False
                            break
                        else:
                            todo.append(T(q, t.switch+1, Q-q))
                todo.sort(key=T.cost, reverse=True)
              except:
                print S, names,
                print Q, queries
                print todo
                print t, q, R, i+1
                raise
        print 'Case #%d:'%(i+1), R

if __name__=='__main__':
    main()
