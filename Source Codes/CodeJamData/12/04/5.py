import sys

def gcd(a, b):
    if a > b:
        return gcd(b, a)

    if a == 0:
        return b
    return gcd(b % a, a)

def lcm(a, b):
    return a * b / gcd(a,b)
def does_hit(mirrors, sx, sy, dx, dy, d):
    k = 1
    if dx:
        k = lcm(abs(dx), k)
    if dy:
        k = lcm(abs(dy), k)
    k *= 2
    # print dx, dy, k

    x = sx * k + k / 2
    y = sy * k + k / 2
    sx = x
    sy = y

    tx = 0
    ty = 0
    # print "starting at %d,%d" % (x, y)
    while True:
        x += dx
        y += dy
        tx += abs(dx)
        ty += abs(dy)

        if tx ** 2 + ty ** 2 > (k * d) ** 2:
            break
        # print "at %d,%d, travelled %d,%d (out of %d)" % (x, y, tx, ty, k*d)

        if x == sx and y == sy:
            # print "back!"
            return True

        mx = (x % k) == 0
        my = (y % k) == 0

        if mx and not my:
            kx = x / k
            ky = y / k
            assert dx
            if dx < 0:
                kx -= 1

            if mirrors[ky][kx]:
                dx *= -1
                # print "hitting the wall at", kx, ky

        elif my and not mx:
            kx = x / k
            ky = y / k
            assert dy
            if dy < 0:
                ky -= 1

            if mirrors[ky][kx]:
                dy *= -1
                # print "hitting the wall at", kx, ky

        elif mx and my:
            assert dx
            assert dy

            kkx = kx = x / k
            kky = ky = y / k

            if dx < 0:
                kkx -= 1
            else:
                kx -= 1
            if dy < 0:
                kky -= 1
            else:
                ky -= 1

            # print "going %d %d" % (dx, dy)
            # print "corner is %d %d" % (kkx, kky)
            # print "x side is %d %d" % (kx, kky)
            # print "y side is %d %d" % (kkx, ky)

            hc = mirrors[kky][kkx]
            hx = mirrors[kky][kx]
            hy = mirrors[ky][kkx]

            if hc:
                if hx and hy:
                    # print "bounce back"
                    dx *= -1
                    dy *= -1
                elif hx:
                    # print "horizontal wall"
                    dy *= -1
                elif hy:
                    # print "vertical wall"
                    dx *= -1
                else:
                    # print "corner dead on"
                    return False

    return False

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    for _t in xrange(t):
        h,w,d = map(int, f.readline().split())

        mirrors = []
        for i in xrange(h):
            l = f.readline()
            m = []
            mirrors.append(m)
            for j in xrange(w):
                if l[j] == '#':
                    m.append(True)
                elif l[j] == '.':
                    m.append(False)
                elif l[j] == 'X':
                    m.append(False)
                    start_x, start_y = j, i
                else:
                    assert False

        num = 0
        for dx in xrange(-d, d+1):
            for dy in xrange(-d, d+1):
                if gcd(abs(dx), abs(dy)) > 1:
                    continue
                if dx ** 2 + dy ** 2 > d ** 2:
                    continue
                if dx == 0 and dy == 0:
                    continue

                if does_hit(mirrors, start_x, start_y, dx, dy, d):
                    # print "HIT"
                    # print dx, dy
                    num += 1
                # print


        del start_x, start_y
        print "Case #%d: %d" % (_t + 1, num)
