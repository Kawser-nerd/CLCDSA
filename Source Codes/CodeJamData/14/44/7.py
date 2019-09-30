import sys


def fact(N):
    global fbuf
    if N in fbuf:
        return fbuf[N]
    if N == 0:
        return 1
    fbuf[N] = N * fact(N - 1)
    return fbuf[N]


def comb(N, k):
    global cbuf
    if (N, k) in cbuf:
        return cbuf[(N, k)]
    if k == 0 or k == N:
        return 1
    cbuf[(N, k)] = comb(N - 1, k - 1) + comb(N - 1, k)
    return cbuf[(N, k)]


def count_c(N, all_c, idx, remaining, buf):
    if (idx, remaining) in buf:
        return buf[(idx, remaining)]
    if idx == len(all_c):
        if remaining == 0:
            return 1
        return 0
    p = 0
    k = all_c[idx]
    for i in xrange(k + 1):
        if i > remaining or k - i > N - remaining:
            continue
        p += comb(remaining, i) * comb(N - remaining, k - i) * count_c(N, all_c, idx + 1, remaining - i, buf) * fact(i) * fact(k - i) * comb(k, i)
        p %= 1000000007
    buf[(idx, remaining)] = p
    return p


def propagate(N, pc):
    prod_p = 1
    sum_c = 0
    max_c = 0
    for p, c in pc:
        prod_p = (prod_p * p) % 1000000007
        sum_c += c
        max_c = max(c, max_c)
    if max_c == N:
        return prod_p, N
    if sum_c <= N:
        prod_p = 1
        for i in xrange(sum_c):
            prod_p = (prod_p * (N - i)) % 1000000007
        return prod_p, sum_c
    all_c = [c for p, c in pc]
    all_c = sorted(all_c, reverse=True)
    buf = {}
    p = count_c(N, all_c, 0, N, buf)
    return p, N


def calculate(trie, buf, N, s):
    if s in buf:
        return buf[s]
    is_node, children = trie[s]
    if len(children) == 0:
        return 1, N, 1
    pc = []
    if is_node:
        pc.append((N, 1))
    new_w = 0
    for child in children:
        w, p, c = calculate(trie, buf, N, child)
        pc.append((p, c))
        new_w += w
    new_p, new_c = propagate(N, pc)
    new_w += new_c
    buf[s] = (new_w, new_p, new_c)
    return buf[s]


def add_to_trie(trie, s):
    for i in xrange(len(s)):
        trie.setdefault(s[:i], [False, set()])
        trie[s[:i]][1].add(s[:(i+1)])
    trie.setdefault(s, [False, set()])
    trie[s][0] = True


def compute(M, N, S):
    trie = {}
    buf = {}
    for s in S:
        add_to_trie(trie, s)
    worst, count, _x = calculate(trie, buf, N, "")
    count = count % 1000000007
    return "%d %d" % (worst, count)


def parse():
    M, N = map(int, sys.stdin.readline().strip().split())
    S = []
    for i in xrange(M):
        S.append(sys.stdin.readline().strip())
    return M, N, S


if __name__ == "__main__":
    global cbuf
    global fbuf
    cbuf = {}
    fbuf = {}
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
