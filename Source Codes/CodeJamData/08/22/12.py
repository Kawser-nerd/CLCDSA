import sys, UnionFind
data = filter(None, map(lambda x:x.strip(), open(sys.argv[1]).readlines()))

from datetime import datetime

class UnionFind():
    def __init__(self):
        self.sets = []
        self.lookup = {}
    def make_set(self, item):
        new_set = [item]
        self.sets.append(new_set)
        self.lookup[item] = new_set
    def find(self, item):
        return self.lookup[item]
    def union(self, set1, set2):
        """Merges set1 into set2"""
        if set1 == set2:
            return
        assert(set1 in self.sets)
        assert(set2 in self.sets)
        for (item, value) in self.lookup.iteritems():
            if value == set1:
                self.lookup[item] = set2
        self.sets.remove(set1)
        set2.extend(set1)
    def as_lists(self):
        return self.sets

def primes(n):
    """ returns a list of prime numbers from 2 to < n """
    # Copied from the web at http://www.daniweb.com/code/snippet305.html
    if n < 2:  return []
    if n == 2: return [2]
    # do only odd numbers starting at 3
    s = range(3, n, 2)
    # n**0.5 may be slightly faster than math.sqrt(n)
    mroot = n ** 0.5
    half = len(s)
    i = 0
    m = 3
    while m <= mroot:
        if s[i]:
            j = (m * m - 3)//2
            s[j] = 0
            while j < half:
                s[j] = 0
                j += m
        i = i + 1
        m = 2 * i + 3
    # make exception for 2
    return [2]+[x for x in s if x]

PRIMES_TO_1K = primes(1000)

def pop_int(data):
    return int(data.pop(0))

def pop_ints(data):
    return map(int, data.pop(0).split())

def pop_rows(data, num_rows):
    result = data[:num_rows]
    for i in range(num_rows):
        data.pop(0)
    return result

def pop_case(data):
    return pop_ints(data)

def primes_between(low, high):
    global PRIMES_TO_1K
    return filter(lambda x: low <= x <= high, PRIMES_TO_1K)

def solve(start, end, prime):
    uf = UnionFind()
    numbers = range(start, end + 1)
    for num in numbers:
        uf.make_set(num)
    for prime in primes_between(prime, end - start):
        #print "Merging on", prime
        divisible = filter(lambda x: not (x % prime), numbers)
        if divisible:
            rep = divisible[0]
            for second in divisible[1:]:
                #print "Merging %d into %d" % (second, rep)
                s1, s2 = uf.find(rep), uf.find(second)
                uf.union(s1, s2)
    #print uf.as_lists()
    return len(uf.as_lists())


num_cases = pop_int(data)
for case_num in range(1, num_cases+1):
    start, end, prime = pop_case(data)
    answer = solve(start, end, prime)
    print "Case #%d: %s" % (case_num, answer)
    





