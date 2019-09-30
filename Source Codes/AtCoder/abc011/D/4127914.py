def main():
    n, d = [int(x) for x in input().split()]
    x, y = [int(x) for x in input().split()]
    if x % d != 0 or y % d != 0:
        return 0.0
    x = abs(x // d)
    y = abs(y // d)
    m = n - x - y
    if m < 0 or m % 2 != 0:
        return 0.0
    ans = 0.0
    for rl in range(x, x + m + 1, 2):
        r = (x + rl) // 2
        l = rl - r
        tb = n - rl
        t = (y + tb) // 2
        b = tb - t
        # ans += comb(n, rl) * comb(rl, r) * comb(tb, t) / (4.0 ** n)
        # ans += fact(n) // fact(r) // fact(l) // fact(t) // fact(b) / 4.0 ** n
        p = 1.0
        i = 1
        for j in range(1, r + 1):
            p *= i / (4.0 * j)
            i += 1
        for j in range(1, l + 1):
            p *= i / (4.0 * j)
            i += 1
        for j in range(1, t + 1):
            p *= i / (4.0 * j)
            i += 1
        for j in range(1, b + 1):
            p *= i / (4.0 * j)
            i += 1
        ans += p
    return ans


print(main())