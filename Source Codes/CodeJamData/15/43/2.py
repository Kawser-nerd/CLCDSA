import sys


def compute(N, sentences):
    b = {}
    for i in xrange(N):
        n = 1 << i
        for w in sentences[i]:
            if w not in b:
                b[w] = n
            else:
                b[w] |= n
    counts = [0] * (1024 * 1024)
    for v in b.values():
        counts[v] += 1
    values = tuple(set(b.values()))
    cmin = 1000000000
    for i in xrange(1, 1 << N, 4):
        c = 0
        for a in values:
            x = a & i
            if x == a or x == 0:
                continue
            c += counts[a]
        cmin = min(c, cmin)
    return cmin


def parse():
    N = int(sys.stdin.readline().strip())
    sentences = []
    for i in xrange(N):
        sentences.append(sys.stdin.readline().strip().split())
    return N, sentences


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
