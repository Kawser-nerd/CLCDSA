def solve(string):
    n, *fp = string.split()
    n = int(n)
    f = fp[:10 * n]
    p = list(map(int, fp[10 * n:]))
    ans = -n * 10**7
    int_f = [int("".join(f[10 * i:10 * (i + 1)]), 2) for i in range(n)]
    for o in range(1, 2**10):
        tmp = [sum(map(int, "{:b}".format(o & _f))) for _f in int_f]
        ans = max(ans, sum([p[11 * i + t] for i, t in enumerate(tmp)]))
    return str(ans)


if __name__ == '__main__':
    n = int(input())
    print(solve('{}\n'.format(n) + '\n'.join([input() for _ in range(2 * n)])))