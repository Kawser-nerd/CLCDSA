from itertools import chain


for i in range(int(input())):
    n, m = tuple(map(int, input().split()))
    l = dict(chain.from_iterable(map(lambda j: zip(zip([j] * m, range(m)), map(int, input().split())), range(n))))
    ans = "YES"

    while len(l):
        ly, lx = min(l, key=l.get)
        lowest = l[(ly, lx)]

        if all(map(lambda j: l.get((ly, j), lowest) == lowest, range(m))):
            for j in range(m):
                l.pop((ly, j), None)

        elif all(map(lambda j: l.get((j, lx), lowest) == lowest, range(n))):
            for j in range(n):
                l.pop((j, lx), None)

        else:
            ans = "NO"
            break

    print("Case #{}: {}".format(i + 1, ans))
