#!/usr/bin/python

import sys
import collections
from array import array

class Solve:

    def __init__(self):
        self.CC = 0                      # chest count
        self.Chest_type = dict()         # chest -> type
        self.Chest_keys = dict()         # chest -> list of keys

        self.type_chests = collections.defaultdict(set)        
                                        # type -> chests
        self.keys_count = collections.defaultdict(lambda: 0)         
                                        # type -> keycount
        self.total_keys_count = collections.defaultdict(lambda: 0)         
                                        # type -> keycount
        self.keys_type_set = set()      # set of types with keys


        self.sol = []
        self.cnt = 0

    def read_problem(self,f):
        kc, self.CC = map(int, f.readline().strip().split())
        keys = map(int, f.readline().strip().split())
        assert(len(keys) == kc)

        for kt in keys:
            self.keys_count[kt] += 1
            self.keys_type_set.add(kt)
            self.total_keys_count[kt] += 1

        for ci in range(self.CC):
            chest = ci+1
            l = map(int, f.readline().strip().split())
            tp = l[0]
            cnt = l[1]
            assert(len(l[2:]) == cnt)

            self.Chest_type[chest] = tp
            self.Chest_keys[chest] = l[2:]
            self.type_chests[tp].add(chest)

            for kt in self.Chest_keys[chest]:
                self.total_keys_count[kt] += 1

    def check_possible1(self):
        for tp, cset in self.type_chests.items():
            if len(cset) > self.total_keys_count[tp]:
                return False

        return True

    def check_possible2(self):
        reached = set()
        types_used = set()

        s = self.keys_type_set.copy()
        while s:
            ss = s.copy()
            for tp in ss:
                assert(tp not in types_used)
                types_used.add(tp)
                s.remove(tp)
                for chest in self.type_chests[tp]:
                    reached.add(chest)
                    for kt in self.Chest_keys[chest]:
                        if kt in types_used: continue
                        s.add(kt)

        return len(reached) == self.CC - len(self.sol)

    def solve(self):
        if not self.check_possible1():
            print "XX"
            return False
        if not self.check_possible2():
            print "YY"
            return False
        return self.solve_rec(False)

    def solve_rec(self, check):
        if len(self.sol) == self.CC: return True

        if check: 
            if not self.check_possible2(): return False

        pchests = array('B')
        for tp in self.keys_type_set: pchests.extend(self.type_chests[tp])

        pchests = sorted(pchests)

        for chest in pchests:
            #print "-- %s: %s" % (self.sol, chest)
            assert(chest >= 1 and chest <= self.CC)
            tp = self.Chest_type[chest]

            self.type_chests[tp].remove(chest)

            keys_type_set = self.keys_type_set.copy()
            
            cnt = self.keys_count[tp]
            assert(cnt > 0)
            if cnt == 1: self.keys_type_set.remove(tp)
            self.keys_count[tp] -= 1

            self.sol.append(chest)
            for ctp in self.Chest_keys[chest]:
                self.keys_type_set.add(ctp)
                self.keys_count[ctp] += 1

            if self.solve_rec(cnt == 1): return True

            for ctp in self.Chest_keys[chest]:
                self.keys_count[ctp] -= 1

            self.sol = self.sol[:-1]
            self.keys_type_set = keys_type_set
            self.keys_count[tp] += 1
            self.type_chests[tp].add(chest)

        return False

# -------------------------------------------------------------------------------------------------

fin = open(sys.argv[1], "r")
fout = open("out.txt", "w")

n = int(fin.readline())

for i in range(n):
    s = Solve()
    s.read_problem(fin)
    if s.solve():
        sol = " ".join(map(str, s.sol))
    else:
        sol = "IMPOSSIBLE"

    fout.write("Case #%d: %s\n" % (i+1, sol))
    fout.flush()



















    







