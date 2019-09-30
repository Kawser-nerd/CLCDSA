def calc(K, xyc):
    K2 = K * 2
    N = len(xyc)

    p = [[0] * K2 for i in range(K2)]
    for x, y, c in xyc:
        y += c * K
        p[x % K2][y % K2] += 1
        p[(x + K) % K2][(y + K) % K2] += 1

    def calcsum(xs):
        r = sum(xs[:K])
        yield r
        for a, b in zip(xs[:K], xs[K:]):
            r += -a + b
            yield r

    pksum = [list(calcsum(xs)) for xs in p]

    rmax = N / 2
    for y in range(K):
        rcount = sum(row[y] for row in pksum[:K])
        for x in range(K):
            rmax = max(rmax, rcount, N - rcount)
            rcount += -pksum[x][y] + pksum[x + K][y]

    return rmax

if __name__ == '__main__':
    N, K = [int(e) for e in input().split()]
    xyc = [(int(x), int(y), c == "W") for x, y, c in [input().split() for i in range(N)]]
    print(calc(K, xyc))