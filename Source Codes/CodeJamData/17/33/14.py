import functools
import operator


def work():
    n, k = map(int, input().split())
    u = float(input())
    ps = list(map(float, input().split()))

    def f(v):
        return functools.reduce(operator.mul, (max(p, v) for p in ps))

    def search(a, b, it):
        if it == 100:
            return a
        c = 0.5 * (a + b)
        return search(c, b, it + 1) if sum(max(0, c - p) for p in ps) <= u else search(a, c, it + 1)

    return f(search(0, 1, 0))


for t in range(int(input())):
    print('Case #{}: {:.7f}'.format(t + 1, work()))
