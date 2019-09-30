from fractions import gcd
from itertools import chain


def eratosthenes_generator():
    yield 2
    n = 3
    h = {}
    while True:
        m = n
        if n in h:
            b = h[n]
            m += 2 * b
            while m in h:
                m += 2 * b
            h[m] = b
            del h[n]
        else:
            m += 2 * n
            while m in h:
                m += 2 * n
            h[m] = n
            yield n
        n += 2


def solve(n):
    if n == 2:
        return [[2, 3], [5, 4]]

    ans = [[0] * n for _ in range(n)]
    eg = eratosthenes_generator()
    primes = [next(eg) for _ in range(2 * n)]
    primes = list(chain.from_iterable(zip(primes, primes[::-1])))
    ps = primes[:n]
    qs = primes[n:2 * n]
    m = (n - 1) // 2

    for i in range(n):
        for j in range(i % 2, n, 2):
            l1 = ps[(i + j) // 2 - m]
            l2 = qs[(i - j) // 2]
            ans[i][j] = l1 * l2

    for i in range(n):
        for j in range((i % 2) ^ 1, n, 2):
            surroundings = []
            if i > 0:
                surroundings.append(ans[i - 1][j])
            if i < n - 1:
                surroundings.append(ans[i + 1][j])
            if j > 0:
                surroundings.append(ans[i][j - 1])
            if j < n - 1:
                surroundings.append(ans[i][j + 1])
            lcm = surroundings[0]
            for s in surroundings[1:]:
                lcm = lcm * s // gcd(lcm, s)
            ans[i][j] = lcm + 1

    return ans


def check(ans):
    for i in range(n):
        for j in range(n):
            x = ans[i][j]
            assert x <= 1e15, x
            if i > 0:
                y = ans[i - 1][j]
                assert max(x, y) % min(x, y) == 1
            if i < n - 1:
                y = ans[i + 1][j]
                assert max(x, y) % min(x, y) == 1
            if j > 0:
                y = ans[i][j - 1]
                assert max(x, y) % min(x, y) == 1
            if j < n - 1:
                y = ans[i][j + 1]
                assert max(x, y) % min(x, y) == 1
    print('OK')


n = int(input())
ans = solve(n)
# check(ans)
print('\n'.join(' '.join(map(str, row)) for row in ans))