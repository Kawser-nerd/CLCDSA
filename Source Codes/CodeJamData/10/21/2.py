import sys
rl = lambda: sys.stdin.readline().strip()

def add(here, tokens):
    if len(tokens) == 0: return 0
    ret = 0
    if tokens[0] not in here:
        ret = 1
        here[tokens[0]] = {}
    return ret + add(here[tokens[0]], tokens[1:])

t = int(rl())
for cc in range(t):
    n, m = map(int, rl().split())
    root = {}
    for i in range(n):
        existing = rl()
        add(root, existing.split("/")[1:])
    ret = 0
    for i in range(m):
        new = rl()
        ret += add(root, new.split("/")[1:])
    print "Case #%d: %d" % (cc+1, ret)
