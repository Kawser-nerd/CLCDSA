
"""
def consistent(l, w):
    if len(l) == 1:
        return
    a, x = w % 2, w // 2
    assert((a == 0) == (0 in l[-1]))
    v = l[:-1]
    #consistent(v, x)


def solve(b, m):
    if m > 2 ** (b - 2):
        print("IMPOSSIBLE")
        return
    for a in range(2):
        u = 2 * m + a + 1
        if u >= 2 ** (b - 1):
            continue
        dec = list(reversed([(u >> i) & 1 for i in range(b - 1)]))
        print(dec)
        #a, x = 0, 1
        w = 2
        z = 1
        l = [[], [0]]
        for i, bit in enumerate(dec):
            z = 2 * z + bit
            a, x = w % 2, w // 2
            consistent(l, w)
            if bit == 1:
                if a == 0:
                    assert (0 in l[-1])
                    new = list(l[-1]) + [i + 1]
                else:
                    assert (0 not in l[-1])
                    new = list(l[-1]) + [i + 1] + [0]
                assert (0 in new)
                w = 2 * w
            else:
                if a == 0:
                    assert (0 in l[-1])
                    new = list(l[-1]) + [i + 1]
                    new.remove(0)
                else:
                    assert (0 not in l[-1])
                    new = list(l[-1]) + [i + 1]
                assert (0 not in new)
                w = 2 * w - 1
            print(new, w)
            l.append(new)
            assert(w == z + 1)
            consistent(l, w)
            print(l)
            print(w // 2, w % 2)
    """

def solve(b, m):
    if m > 2 ** (b - 2):
        print("IMPOSSIBLE")
        return
    print("POSSIBLE")
    if m == 2 ** (b - 2):
        print("0" + "1" * (b - 1))
    else:
        l = [(m >> i) & 1 for i in range(b - 2)]
        print("0" + "".join(map(str, reversed(l))) + "0")
    for i in range(1, b):
        print("0" * (i + 1) + "1" * (b - i - 1))


t = int(input())
for i in range(t):
    print("Case #" + str(i + 1) + ":", end = " ")
    b, m = map(int, input().split())
    solve(b, m)
