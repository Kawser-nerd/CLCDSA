def f(_b, _n):
    ret = 0
    while _n > 0:
        ret += _n % _b
        _n = _n // _b
    return ret
INF = 10 ** 12

n = int(input())
s = int(input())

ans = INF
if n >= s:
    max_digits = len(str(bin(n))) - 2
    # 3???
    for k in range(max_digits, 2, -1):
        min_b = max(2, -(int(- (n ** (1 / k)))))
        max_b = int((n - s + 1) ** (1 / (k - 1)))
        for b in range(min_b, max_b + 1, 1):
            if f(b, n) == s:
                ans = b
                break
        if ans != INF:
            break

    if ans == INF:
        # 2?
        for a1 in range(1, s + 1):
            if (n - s) < (a1 - 1) * a1:
                break
            if (n - s) % a1 == 0:
                a0 = s - a1
                b = (n - a0) // a1
                if a0 < b and a1 < b and (b * a1) == (n - a0) and b < ans:
                    ans = b

    if ans == INF:
        # 1?
        if n == s:
            ans = n + 1
if ans == INF:
    ans = -1

print(ans)