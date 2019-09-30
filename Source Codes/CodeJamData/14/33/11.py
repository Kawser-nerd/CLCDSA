import itertools

def valid(seq):
    for i in xrange(len(seq)-1):
        if abs(seq[i] - seq[i+1]) > 2:
            return False
    return True

def solve(case):
    n, m, k = case
    if min(n, m) <= 2:
        return k
    if k <= 4:
        return k
    count = k
    for i in xrange(1,n+1):
        for seq in itertools.product(range(1,m+1), repeat = i):
            if sum(seq) == k and valid(seq):
                count = min(count, seq[0] + seq[-1] + 2* len(seq) - 4)
    return count

f = file('c.in', 'r')
lines = f.readlines()
t = int(lines[0])
f.close()

g = file('c.out', 'w')

for i in xrange(1, t+1):
    s = solve( map(int, lines[i].strip().split()) )
    g.write("Case #{}: {}\n".format(i, s))
g.close()
