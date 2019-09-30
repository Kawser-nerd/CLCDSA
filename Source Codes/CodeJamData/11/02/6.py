from collections import defaultdict

def rins():
    return raw_input().strip()

def read_testcase():
    values = rins().split()
    combinations = int(values[0])
    values = values[1:]
    combination_strings = values[:combinations]
    values = values[combinations:]
    opposites = int(values[0])
    values = values[1:]
    opposite_strings = values[:opposites]
    values = values[opposites:]
    invocation = values[1]
    return Chemistry(combination_strings, opposite_strings), invocation

class Chemistry(object):
    def __init__(self, combinations, opposites):
        self.combinations = dict(
            (frozenset([a,b]), c) for (a,b,c) in combinations)
        self.opposites = defaultdict(frozenset)
        for (a,b) in opposites:
            self.opposites[a] |= frozenset([b])
            self.opposites[b] |= frozenset([a])

def solve(chemistry, invocation):
    stack = []
    counters = defaultdict(int)
    for element in invocation:
        stack.append(element)
        counters[element]+=1
        while True:
            if len(stack)<2:
                break
            mix = frozenset(stack[-2:])
            if mix not in chemistry.combinations:
                break
            counters[stack.pop()] -= 1
            counters[stack.pop()] -= 1
            result = chemistry.combinations[mix]
            stack.append(result)
            counters[result] += 1
        if len(stack)>=2:
            element = stack[-1]
            opposites = chemistry.opposites[element]
            for o in opposites:
                if counters[o]>0:
                    stack = []
                    counters.clear()
                    break
    return stack

def solve_next():
    chemistry, invocation = read_testcase()
    return solve(chemistry, invocation)

def run():
    n = int(rins())
    for i in xrange(n):
        print "Case #{0}: [{1}]".format(i+1, ', '.join(solve_next()))

run()
