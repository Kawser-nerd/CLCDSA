from itertools import groupby


def solve():
    n, k = [int(w) for w in input().split()]
    a = [(n, 1)]
    while True:
        b = []
        for d, cnt in a:
            if cnt < k:
                k -= cnt
                b.append(((d - 1) // 2, cnt))
                b.append((d // 2, cnt))
            else:
                return "{} {}".format(d // 2, (d - 1) // 2)

        a = [(f, sum(s for _, s in g)) for f, g in groupby(sorted(b), key=lambda t: t[0])]
        a = list(reversed([x for x in a if x[0] > 0]))


def prepare_input():
    local = False
    task = 'C'
    attempt = -1

    import sys

    if local:
        sys.stdin = open("../input.txt", "r")
    else:
        filename = "../{}-small-2-attempt{}".format(task, attempt) if attempt >= 0 else "../{}-large".format(task)

        sys.stdin = open(filename + ".in", "r")
        sys.stdout = open(filename + ".out", "w")

        print("filename:", filename[3:], file=sys.stderr)


prepare_input()
tests = int(input())
for test in range(1, tests + 1):
    res = solve()
    print("Case #{}: {}".format(test, res))
