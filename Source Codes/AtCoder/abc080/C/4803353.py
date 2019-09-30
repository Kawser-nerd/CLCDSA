def solve(string):
    n, *fp = map(int, string.split())
    f = "".join(map(str, fp[:10 * n]))
    p = fp[10 * n:]
    int_f = [int(f[10 * i:10 * (i + 1)], 2) for i in range(n)]
    return str(
        max(
            sum([p[11 * i + bin(o & _f).count("1")]
                 for i, _f in enumerate(int_f)])
            for o in range(1, 2**10)))


if __name__ == '__main__':
    n = int(input())
    print(solve('{}\n'.format(n) + '\n'.join([input() for _ in range(2 * n)])))