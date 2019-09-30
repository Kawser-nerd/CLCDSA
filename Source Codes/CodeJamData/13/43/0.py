import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N = int(f.readline())
        A = map(int, f.readline().split())
        B = map(int, f.readline().split())
        assert len(A) == N
        assert len(B) == N, len(B)

        gt = [[False] * N for i in xrange(N)]
        for i in xrange(N):
            for j in xrange(i+1, N):
                if A[i] >= A[j]:
                    gt[i][j] = True
            for j in xrange(i-1, -1, -1):
                if A[j] == A[i] - 1:
                    gt[i][j] = True
                    break

            for j in xrange(i):
                if B[i] >= B[j]:
                    gt[i][j] = True
            for j in xrange(i+1, N):
                if B[j] == B[i] - 1:
                    gt[i][j] = True
                    break
        # print
        # for i in xrange(N):
            # print i, map(int, gt[i])

        v = [0] * N
        r = 0
        while r < N:
            for i in xrange(N):
                if v[i] == 0 and all(not gt[i][j] or v[j] for j in xrange(N)):
                    v[i] = r + 1
                    r += 1
                    break
            else:
                raise Exception()
        print "Case #%d: %s" % (_T+1, ' '.join(map(str, v)))
