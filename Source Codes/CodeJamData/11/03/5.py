def rins():
    return raw_input().strip()


def solve(sequence):
    values = list(sequence)
    values.sort()
    if reduce(lambda a,b:a^b, values) == 0:
        return sum(values[1:])
    else:
        return "NO"

def solve_next():
    rins()
    numbers = map(int, rins().split())
    return solve(numbers)

def run():
    n = int(rins())
    for i in xrange(n):
        print "Case #{0}: {1}".format(i+1, solve_next())

run()
