def solve(string):
    n, k, *a = map(int, string.split())
    if k == 0:
        x = 0
    else:
        l = len("{:b}".format(k))
        base = [2**(l - i - 1) for i in range(l)]
        count = [0] * l
        for _a in a:
            tmp = "{:b}".format(_a)
            for i, _f in enumerate(tmp[::-1]):
                if i >= l:
                    break
                if _f == "1":
                    count[l - i - 1] += 1
        x = 0
        for _c, _b in zip(count, base):
            if _c < n / 2 and x + _b <= k:
                x += _b
    return str(sum([x ^ _a for _a in a]))


if __name__ == '__main__':
    print(solve('\n'.join([input(), input()])))