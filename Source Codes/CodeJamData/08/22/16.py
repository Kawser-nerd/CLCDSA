import sets

def sieve():       
    from math import sqrt
    max = 1000
    maxpossible = int(sqrt(max))
    nums = range(2, max) 
    for i in range(2, maxpossible): 
        nums = filter(lambda x: x == i or x % i, nums)
    return nums
    
def prime_factors():
    max = 1000
    x = [[] for i in range(0, max + 1)]
    x[0] = [1]
    x[1] = [1]
    primes = sieve()
    for i in range(2, max + 1):
        for prime in primes:
            if i % prime == 0:
                x[i].append(prime)
    for i in range(len(x)):
        x[i] = sets.Set(x[i])
    return x

factors = prime_factors()
intersections = [[0 for j in range(1001)] for i in range(1001)]
for i in range(1001):
    for j in range(1001):
        fx = factors[i]
        fy = factors[j]
        inter = fx.intersection(fy)
        if len(inter) > 0:
            intersections[i][j] = max(inter)

class Case:
    def __init__(self, s):
        self.line = map(int, s.read().split(" "))

    def solve(self):
        a,b,p = self.line
        self.all_sets = [[i] for i in range(a, b + 1)]
        possible = True
        while possible:
            possible = False
            for i in range(len(self.all_sets) - 1):                       
                for j in range(i + 1, len(self.all_sets)):   
                    if j >= len(self.all_sets):
                        break
                    for x in self.all_sets[i]:
                        removed = False
                        for y in self.all_sets[j]:
                            if intersections[x][y] >= p:
                                self.merge_sets(i, j)
                                removed = True
                                possible = True
                                break
                        if removed:
                            j -= 1
                            break                        
        return len(self.all_sets)
    
    def gcf(self, a, b):
       if b == 0:
           return a
       return self.gcf(b, a%b)
   
    def merge_sets(self, i, j):
       self.all_sets[i] = self.all_sets[i] + self.all_sets[j]
       self.all_sets.remove(self.all_sets[j])

        
class Contents:
    def __init__(self, f):
        self.data = [line.strip() for line in f]
        self.i = 0

    def read(self):
        return self.readList(1)[0]

    def readList(self, len):
        result = self.data[self.i : self.i + len]
        self.i += len
        return result

import sys
f = file(sys.argv[1])
s = Contents(f)
numCases = int(s.read())

for caseNum in range(numCases):
    case = Case(s)
    print "Case #%d: %s" % (caseNum + 1, case.solve())
