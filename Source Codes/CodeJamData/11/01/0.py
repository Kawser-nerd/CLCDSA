import sys

def doit(points):
    last_pos = [1,1]
    last_time = [0,0]
    last_press = 0

    for i, x in points:
        diff = abs(x - last_pos[i])
        last_time[i] += diff
        last_pos[i] = x
        last_time[i] = max(last_time[i], last_press)

        last_time[i] += 1
        last_press = last_time[i]

    return last_press

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    d = {'O':0, 'B':1}
    for _t in xrange(t):
        s = f.readline().split()[1:]
        points = [(d[s[i]], int(s[i+1])) for i in xrange(0, len(s), 2)]
        n = doit(points)
        print "Case #%d: %d" % (_t+1, n)

