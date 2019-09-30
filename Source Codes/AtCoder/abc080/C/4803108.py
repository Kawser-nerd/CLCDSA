from itertools import product
import numpy as np


def solve(string):
    n, *fp = map(int, string.split())
    # f = np.asarray(fp[:10 * n]).reshape((n, 10))
    f = fp[:10 * n]
    p = fp[10 * n:]
    ans = -n * 10**7
    """
    for o in product([0, 1], repeat=10):
        if sum(o) == 0:
            continue
        # tmp = np.dot(f, np.asanyarray(o).T)
        tmp = [sum([for ]) for _f in f]
        ans = max(ans, sum([p[11 * i + t] for i, t in enumerate(tmp)]))
    return str(ans)
    """
    int_f = [int("".join(map(str, f[10 * i:10 * (i + 1)])), 2) for i in range(n)]
    for o in range(1, 2**10):
        tmp = [sum(map(int, "{:b}".format(o & _f))) for _f in int_f]
        ans = max(ans, sum([p[11 * i + t] for i, t in enumerate(tmp)]))
    return str(ans)


if __name__ == '__main__':
    n = int(input())
    print(solve('{}\n'.format(n) + '\n'.join([input() for _ in range(2 * n)])))