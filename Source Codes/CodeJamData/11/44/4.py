import sys, collections


infile = sys.stdin

class State(object):
    def __init__(self, owned, threatened):
        self.owned = frozenset(owned)
        self.threatened = threatened
        
    def __hash__(self):
        return hash(self.owned)
        
    def __eq__(self, other):
        return self.owned==other.owned


def get_result(wormholes):
    planets = set(wormholes.keys())
    states = set([State(set([0]), wormholes[0])])
    while True:
        best = None
        # check for winner
        for s in states:
            if (1 in s.threatened) and (best is None or len(s.threatened)>len(best.threatened)):
                best = s
        if best: 
            #print best.owned,'\n',best.threatened
            return len(best.owned)-1, len(best.threatened)
        
        # try conquering every threatened planet
        next_states = set()
        for s in states:
            for p in s.threatened:
                newowned = set(s.owned)
                newowned.add(p)
                newthreat = s.threatened.union(wormholes[p]) - newowned
                next_states.add(State(newowned, newthreat))
                
        states = next_states
    

T = int(infile.readline())
for i in xrange(T):
    #print i
    P, W = map(int, infile.readline().split())
    wormholes = {}
    connections = infile.readline().split()
    for c in connections:
        p1, p2 = map(int, c.split(','))
        if p1 not in wormholes: wormholes[p1] = set()
        if p2 not in wormholes: wormholes[p2] = set()
        wormholes[p1].add(p2)
        wormholes[p2].add(p1)
    #print wormholes

    conquered, threatened = get_result(wormholes)

    print("Case #%d: %d %d" % (i+1, conquered, threatened))
