def calc(K, xyc):
    K2 = K * 2
    N = len(xyc)

    p = [[0] * K2 for i in range(K2)]
    for x, y, c in xyc:
        y += c * K
        p[x % K2][y % K2] += 1
        p[(x + K) % K2][(y + K) % K2] += 1

    def isum(xs):
        r = 0
        yield r
        for x in xs:
            r += x
            yield r

    psum = [list(isum(row)) for row in p]
    pksum = [[b - a for a, b in zip(row, row[K:])] for row in psum]

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