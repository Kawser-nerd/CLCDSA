import sys


def mk_string(x, y):
    return " ".join(["%d %d" % (xi, ji) for xi, ji in zip(x, y)])


def can_place(r, W, L, x, y, cx, cy, cr):
    if cx < 0 or cy < 0 or cx > W or cy > L:
        return False
    for i in xrange(len(x)):
        if abs(x[i] - cx) < r[i] + cr and abs(y[i] - cy) < r[i] + cr:
            return False
    return True

def compute(N, W, L, r):
    rr = list(reversed(sorted(r)))
    x = [0, W]
    y = [0, L]
    if len(r) < 2:
        return mk_string(x[:len(r)], y[:len(r)])
    px = [0, W]
    py = [0, L]
    for i in xrange(2):
        px.append(x[i] - rr[i])
        px.append(x[i] + rr[i])
        py.append(y[i] - rr[i])
        py.append(y[i] + rr[i])

    for i in xrange(2, len(rr)):
        pxx = [0, W]
        pyy = [0, L]
        for cx, cy in zip(px, py):
            pxx.append(cx - rr[i])
            pxx.append(cx + rr[i])
            pyy.append(cy - rr[i])
            pyy.append(cy + rr[i])
        pxx = sorted(pxx)
        pyy = sorted(pyy)
        found=False
        for cx in pxx:
            if found:
                break
            for cy in pyy:
                if found:
                    break
                if can_place(rr, W, L, x, y, cx, cy, rr[i]):
                    x.append(cx)
                    y.append(cy)
                    px.append(cx - rr[i])
                    px.append(cx + rr[i])
                    py.append(cy - rr[i])
                    py.append(cy + rr[i])
                    found=True
                    break

    done = [False] * N
    rx = [0] * N
    ry = [0] * N
    for i in xrange(len(r)):
        for j in xrange(len(rr)):
            if done[j]:
                continue
            if rr[j] == r[i]:
                rx[i] = x[j]
                ry[i] = y[j]
                done[j] = True
                break
    return mk_string(rx, ry)


def parse():
    N, W, L = map(int, sys.stdin.readline().strip().split(' '))
    r = map(int, sys.stdin.readline().strip().split(' '))
    return (N, W, L, r)


if __name__ == "__main__":
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
