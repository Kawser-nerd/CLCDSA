import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N, K = map(int, f.readline().split())

        amounts = {N: 1}
        K -= 1

        while K:
            next = max(amounts.keys())
            num = amounts[next]
            if num > K:
                break
            del amounts[next]
            # print "%d -> %d/%d" % (next, (next-1)/2, next / 2)
            amounts[(next - 1) / 2] = amounts.get((next - 1) / 2, 0) + num
            amounts[next / 2] = amounts.get(next / 2, 0) + num
            K -= num

        next = max(amounts.keys())

        print "Case #%d: %d %d" % (_T + 1, next / 2, (next - 1) / 2)
