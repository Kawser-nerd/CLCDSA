#!/usr/bin/python2
### Google Code Jam template
## Library
# @memoized
def memoized(func):
    mem = {}
    def wrapped(*args):
        if args not in mem:
            mem[args] = func(*args)
        return mem[args]
    return wrapped

## Setup
# Task letter
TASK="D"

## Input templates
# Line as int
#int(infile.readline())
# Line as many ints
#(int(s) for s in infile.readline().split())

## Precalculation
#print("Precalculation...")
#print("Precalculation done.")

## Calculation
class Planet():
    def __init__(self, num):
        self.id = num
        self.nbs = set()
        self.gen = None
        self.ways = dict()
    def __repr__(self):
        return "<Planet #"+str(self.id)+">"
    def update(self, gen):
        if self.gen is not None and self.gen < gen:
            return False
        else:
            self.gen = gen
            return True
    
print("Calculation...")
with open(TASK+".in") as infile:
    with open(TASK+".out",mode="wt") as outfile:
        cases = int(infile.readline())
        for ncase in range(cases):
            print("Test #{ncase}".format(ncase=ncase+1))
            # Perform all nessesary calculation
            # Read and build the neighbourship data
            P, W = (int(s) for s in infile.readline().split())
            planets = [Planet(i) for i in xrange(P)]
            earth = planets[0]
            AI = planets[1]
            for s in infile.readline().split():
                x, y = (int(x) for x in s.split(','))
                planets[x].nbs.add(planets[y])
                planets[y].nbs.add(planets[x])
            # Init the wave
            earth.gen = 0
            earth.ways = {None: len(earth.nbs)}
            cur = set()
            gen = 1
            for planet in earth.nbs:
                cur.add(planet)
                planet.gen = gen
                planet.ways[earth] = len(earth.nbs | planet.nbs) - 2
            # Propagate the wave
            while AI.gen is None:
                prev = cur
                cur = set()
                gen += 1
                for src in prev:
                    for dst in src.nbs:
                        if not dst.update(gen):
                            continue
                        cur.add(dst)
                        dst.ways[src] = max(n+len(dst.nbs - src.nbs - s.nbs)-1
                                for s, n
                                in src.ways.items())
            # End of the game
            LG = AI.gen - 1
            threats = (max(last.ways.values())
                    for last in AI.nbs if last.gen == LG)
            outfile.write("Case #{nc}: {C} {T}\n".format(nc=ncase+1,
                          C=LG, T=max(threats)))
print("Calculation done.")
