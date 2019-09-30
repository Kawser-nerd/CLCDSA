from bisect import bisect_left


def solve(string):
    a, b, q, *stx = map(int, string.split())
    s = [-10**10] + stx[:a] + [2 * 10**10]
    t = [-10**10] + stx[a:a + b] + [2 * 10**10]
    x = dict([])
    ans = []
    i_s = 0
    i_t = 0
    # for _x in stx[-q:]:
    for _x in sorted(stx[-q:]):
        # """
        while s[i_s] < _x:
            i_s += 1
        while t[i_t] < _x:
            i_t += 1
        # """
        # i_s, i_t = bisect_left(s, _x), bisect_left(t, _x)
        ls, rs = _x - s[i_s - 1], s[i_s] - _x
        lt, rt = _x - t[i_t - 1], t[i_t] - _x
        r_max = rs if rs > rt else rt
        l_max = ls if ls > lt else lt
        # ans.append(
        x[_x] = str(
            min(r_max, l_max, rt + ls + (rt if rt < ls else ls),
                rs + lt + (rs if rs < lt else lt)))
    return "\n".join([x[_x] for _x in stx[-q:]])
    # return "\n".join(ans)


if __name__ == '__main__':
    n, m, l = map(int, input().split())
    print(solve('{} {} {}\n'.format(n, m, l) + '\n'.join([input() for _ in range(n + m + l)])))