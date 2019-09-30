def solve():
    from operator import mul
    from functools import reduce
    from math import factorial
    N = int(input())
    _a = list(map(int, input().split()))
    a = [_a[0]]
    for n1, n2 in zip(_a, _a[1:]):
        if n1 == n2 == -1:
            a[-1] -= 1
        else:
            a.append(n2)

    ans, mod = 1, 10**9+7
    for i, n in enumerate(a):
        if n > 0:
            continue
        r = -n
        n = a[i+1] - a[i-1] + 1
        comb = reduce(mul, range(n+r-1, n-1, -1)) // factorial(r)
        ans = (ans * comb) % mod

    print(ans)


if __name__ == "__main__":
    solve()