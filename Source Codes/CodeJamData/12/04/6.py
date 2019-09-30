import sys
from functools import wraps

cache = {}

def cached(func):
    @wraps(func)
    def cached_func(*args):
        if args in cache:
            return cache[args]
        cache[args] = func(*args)
        return cache[args]
    return cached_func


def which_side_func(x, y):
    def which_side(point):
        return x * point[1] - y * point[0]
    return which_side

@cached
def make_steps(x, y):
    x *= 2
    y *= 2
    squares = set()
    for i in xrange(min(x, 0), max(x, 0) + 2, 2):
        for j in xrange(min(y, 0), max(y, 0) + 2, 2):
            edges = ((i - 1, j - 1), (i - 1, j + 1), (i + 1, j - 1), (i + 1, j + 1))
            directions = map(which_side_func(x, y), edges)
            if min(directions) < 0 and max(directions) > 0:
                squares.add((i, j))
    i = 0
    j = 0
    DXY = ((-2, 0), (0, 2), (2, 0), (0, -2), (-2, -2), (-2, 2), (2, -2), (2, 2))
    steps = []
    while i != x or j != y:
        squares.discard((i, j))
        for dx, dy in DXY:
            if (i + dx, j + dy) in squares:
                steps.append((dx / 2, dy / 2))
                i += dx
                j += dy
                break
    return steps


def is_reflection(m, sx, sy, steps):
    x = sx
    y = sy
    rx = False
    ry = False
    for dx, dy in steps:
        if rx:
            dx = -dx
        if ry:
            dy = -dy
        if m[x + dx][y + dy] != '#':
            x += dx
            y += dy
            continue
        if dx == 0 or dy == 0:
            if dx == 0:
                ry = not ry
            if dy == 0:
                rx = not rx
            continue
        else:
            if m[x + dx][y] != '#' and m[x][y + dy] != '#':
                return False
            if m[x + dx][y] == '#' and m[x][y + dy] == '#':
                rx = not rx
                ry = not ry
                continue
            if m[x + dx][y] == '#':
                y += dy
                rx = not rx
            else:  # m[x][y + dy] == '#'
                x += dx
                ry = not ry
    return x == sx and y == sy


def gcd(a, b):
    if a < 0:
        a = -a
    if b < 0:
        b = -b
    if a > b:
        return gcd(b, a)
    if a == 0:
        return b
    return gcd(b % a, a)


def count_reflections(m, D):
    for x in xrange(len(m)):
        for y in xrange(len(m[x])):
            if m[x][y] == 'X':
                sx = x
                sy = y
    reflections = set()
    for x in xrange(-D, D + 1):
        for y in xrange(-D, D + 1):
            if x == 0 and y == 0:
                continue
            if x * x + y * y > D * D:
                continue
            steps = make_steps(x, y)
            if is_reflection(m, sx, sy, steps):
                g = gcd(x, y)
                reflections.add((x / g, y / g))
    return len(reflections)


if __name__ == "__main__":
    T = int(sys.stdin.readline().strip())
    for r in xrange(T):
        values = map(int, sys.stdin.readline().strip().split(' '))
        H, W, D = values
        m = []
        for _i in xrange(H):
            m.append(sys.stdin.readline().strip())
        result = count_reflections(m, D)
        print "Case #%d: %s" % (r + 1, result)
