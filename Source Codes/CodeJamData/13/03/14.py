def sqrt(x, ge):
    if x == 1:
        return 1
    sx = x >> 1
    step = sx >> 1

    while step:
        if sx ** 2 >= x:
            sx = sx - step
        else:
            sx = sx + step
        step = step >> 1

    if ge:
        while not sx ** 2 < x:
            sx = sx - 1
        while not sx ** 2 >= x:
            sx = sx + 1
    else:
        while not sx ** 2 > x:
            sx = sx + 1
        while not sx ** 2 <= x:
            sx = sx - 1

    return sx


def get_start_pali(a):
    s = str(a)
    ls = len(s)
    if ls == 1:
        return s, True
    elif ls & 1:
        return s[:(ls >> 1) + 1], True
    else:
        return s[:ls >> 1], False


def get_next_pali(p, m):
    if len(p) == p.count("9"):
        if m:
            return "1" + "0" * (len(p) - 1), False
        else:
            return "1" + "0" * len(p), True
    else:
        return str(int(p) + 1), m


def pali_to_num(p, m):
    if m:
        return int(p + p[-2::-1])
    else:
        return int(p + p[::-1])


def is_pali(a):
    s = str(a)
    hls = len(s) >> 1
    return s[:hls] == s[:-hls - 1:-1]

for i in range(int(input())):
    a, b = tuple(map(int, input().split()))
    sqa, sqb = sqrt(a, True), sqrt(b, False)

    p, m = get_start_pali(sqa)
    while pali_to_num(p, m) < sqa:
        p, m = get_next_pali(p, m)

    count = 0

    while True:
        curr = pali_to_num(p, m)
        if curr > sqb:
            break
        if is_pali(curr ** 2):
            count = count + 1
        p, m = get_next_pali(p, m)

    print("Case #{}: {}".format(i + 1, count))
