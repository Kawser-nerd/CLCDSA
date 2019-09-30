data = iter(open('A-large.in').read().splitlines())
cases = int(next(data))


def possible(m, R, C):
    for row in m:
        if row.count('.') == len(row) - 1:
            pos = None
            for i, c in enumerate(row):
                if c != '.':
                    pos = i
                    break
            cnt = 0
            for r in m:
                if r[pos] != '.':
                    cnt += 1
            if cnt == 1:
                return False
    return True


def solve(m, a, b):
    hits = 0
    for row in m:
        for c in row:
            if c != '.':
                if c == a:
                    hits += 1
                break
        for c in row[::-1]:
            if c != '.':
                if c == b:
                    hits += 1
                break
    return hits


for case in range(1, cases + 1):
    R, C = map(int, next(data).split())
    m = [list(next(data)) for _ in range(R)]
    if not possible(m, R, C):
        ans = "IMPOSSIBLE"
    else:
        ans = str(solve(m, '<', '>') + solve(zip(*m), '^', 'v'))
    print "Case #%d: %s" % (case, ans)
