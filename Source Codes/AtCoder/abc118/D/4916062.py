def solve(string):
    n, m, *a = map(int, string.split())
    needs = {i + 1: n for i, n in enumerate(map(int, "2 5 5 4 5 6 3 7 6".split()))}
    if 2 in a and 5 in a or 2 in a and 3 in a:
        a.remove(2)
    if 3 in a and 5 in a:
        a.remove(3)
    if 6 in a and 9 in a:
        a.remove(6)
    a = sorted(a, key=lambda x: needs[x])
    index = 0
    base = str(a[0]) * (n // needs[a[0]])
    n %= needs[a[0]]
    while n > 0:
        use = [_b for _b in a if needs[_b] <= needs[a[0]] + n]
        if len(use) == 1:
            base = base[:-1]
            n += needs[a[0]]
            continue
        flag = max(use) == a[0]
        tmp_n = use[-1] if flag else max(use)
        diff = needs[tmp_n] - needs[a[0]]
        tmp_c = n // diff
        if flag:
            base = base[:-tmp_c] + str(tmp_n) * tmp_c
        else:
            base = base[:index] + str(tmp_n) * tmp_c + base[index + tmp_c:]
            index += tmp_c
        n -= diff * tmp_c
    return base


if __name__ == '__main__':
    print(solve('\n'.join([input(), input()])))