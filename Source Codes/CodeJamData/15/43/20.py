def cntgg(xs):
    return sum([1 for x in xs if x > 0])


def solve():
    n = int(raw_input())

    words = [raw_input().split() for _ in range(n)]

    cnts = {w: [0, 0] for ws in words for w in ws}

    for i in range(n):
        for word in words[i]:
            cnts[word][0] += 1

    cnt = 0
    ans = 1000 * n
    pbm = 0
    for bm in range(1, 2**n, 4):
        for i in range(n):
            pb = pbm >> i & 1
            b = bm >> i & 1
            if pb == b:
                continue

            for word in words[i]:
                pc = cntgg(cnts[word])

                cnts[word][pb] -= 1
                cnts[word][b] += 1

                c = cntgg(cnts[word])

                if c != pc:
                    if c == 2:
                        cnt += 1
                    elif pc == 2:
                        cnt -= 1

        ans = min(ans, cnt)

        pbm = bm

    return ans


def main():
    tt = int(raw_input())

    for t in range(1, tt+1):
        print 'Case #%d: %d' % (t, solve())

if __name__ == '__main__':
    main()
