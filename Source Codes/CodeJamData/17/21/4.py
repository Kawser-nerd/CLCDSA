tests = int(input())


def solve():
    d, n = map(int, input().split())
    a = []
    t = 0
    for i in range(n):
        s, v = map(int, input().split())
        t = max(t, (d - s) / v)

    return (d / t)

for ti in range(1, tests + 1):
    print("Case #{}: {:0.9f}".format(ti, solve()))
