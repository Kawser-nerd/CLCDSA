from itertools import permutations

def rins():
    return raw_input().strip()

def count_cycles(sequence):
    remaining = set(sequence)
    while remaining:
        item = remaining.pop()
        cycle_length = 0
        while True:
            nextitem = sequence[item-1]
            if nextitem not in remaining:
                break
            cycle_length += 1
            item = nextitem
            remaining.discard(nextitem)
        yield cycle_length

def solve(sequence):
    return sum(x+1 for x in count_cycles(sequence) if x != 0)

def solve_next():
    rins()
    numbers = map(int, rins().split())
    return solve(numbers)

def run():
    n = int(rins())
    for i in xrange(n):
        print "Case #{0}: {1}".format(i+1, 1.0*solve_next())

run()
