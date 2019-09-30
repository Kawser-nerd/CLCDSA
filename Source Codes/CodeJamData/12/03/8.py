import sys

MAX_LIMIT = 2000000


def get_min_mapped(n):
    n_min = n
    x = str(n)
    for i in xrange(1, len(x)):
        x = x[1:] + x[0]
        if x[0] == '0':
            continue
        n_min = min(n_min, int(x))
    return n_min


if __name__ == "__main__":
    T = int(sys.stdin.readline().strip())
    min_mapped = [0] * (MAX_LIMIT + 1)
    for i in xrange(1, MAX_LIMIT + 1):
        min_mapped[i] = get_min_mapped(i)

    for r in xrange(T):
        values = map(int, sys.stdin.readline().strip().split(' '))
        A, B = values
        cnt_mapped = [0] * (B + 1)
        for i in xrange(A, B + 1):
            cnt_mapped[min_mapped[i]] += 1
        total = 0
        for i in xrange(B + 1):
            if cnt_mapped[i] > 1:
                total += (cnt_mapped[i] * (cnt_mapped[i] - 1)) / 2
        print "Case #%d: %s" % (r + 1, total)
