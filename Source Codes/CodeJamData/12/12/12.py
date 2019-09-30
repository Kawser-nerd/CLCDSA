import sys

def compute(N, x):
    state = [0] * len(x)
    stars = 0
    steps = 0
    modified = True
    while modified:
        modified = False
        for i in xrange(len(x)):
            if state[i] == 2:
                continue
            if x[i][1] <= stars:
                steps += 1
                stars += 2 - state[i]
                state[i] = 2
                modified = True
        if modified:
            continue
        tmax = -1
        ti = None
        for i in xrange(len(x)):
            if state[i] != 0: continue
            if x[i][0] <= stars and x[i][1] > tmax:
                tmax = x[i][1]
                ti = i
        if ti is not None:
            state[ti] = 1
            stars += 1
            steps += 1
            modified = True
    if stars == 2 * len(x):
        return "%d" % steps
    else:
        return "Too Bad"


def parse():
    N = int(sys.stdin.readline().strip())
    x = []
    for i in xrange(N):
        a, b = map(int, sys.stdin.readline().strip().split())
        x.append((a, b))
    return N, x


if __name__ == "__main__":
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
