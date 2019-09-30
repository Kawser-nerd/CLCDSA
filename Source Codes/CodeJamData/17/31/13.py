import itertools
import math

ints = lambda: list(map(int, input().split()))

for t in range(int(input())):
    n, k = ints()
    rhs = list(ints() for _ in range(n))
    ans = max(
        math.pi * ri * ri + 2 * math.pi * ri * hi + sum(itertools.islice(reversed(sorted(
            2 * math.pi * rj * hj
            for j, (rj, hj) in enumerate(rhs)
            if j != i
        )), k - 1))
        for i, (ri, hi) in enumerate(rhs)
    )
    print('Case #{}: {:.7f}'.format(t + 1, ans))
