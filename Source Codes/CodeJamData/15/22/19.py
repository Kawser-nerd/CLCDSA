N = input()
def worker(num_4, num_3, num_2, tot, rest):
    assert num_4 >= 0 and num_3 >= 0 and num_2 >= 0
    # 4
    s = min(rest, num_4)
    tot -= 4 * s
    rest, num_4 = rest - s, num_4 - s

    # 3
    s = min(rest, num_3)
    tot -= 3 * s
    rest, num_3 = rest - s, num_3 - s

    # 2
    s = min(rest, num_2)
    tot -= 2 * s
    rest, num_2 = rest - s, num_2 - s

    return tot


for C in range(1, N+1):
    r, c, n = map(int, raw_input().split())

    if (r*c+1)/2 >= n:
        print "Case #%d:" % C, 0
        continue

#    import pdb; pdb.set_trace()
    if r % 2 != 0:
        (r, c) = (c, r)

    tot = c * (r-1) + r * (c-1)
    rest = r * c - n

    if r == 1 or c == 1:
        print "Case #%d:" % C, tot - 2 * rest
        continue

    if r % 2 == 0 and c % 2 == 0:
        num_4 = (c-2) * (r-2) / 2
        num_3 = (r * c / 2) - num_4 - 2
        num_2 = 2

        ans = worker(num_4, num_3, num_2, tot, rest)
    elif r % 2 == 0 and c % 2 != 0:
        num_4 = (c-2) * (r-2) / 2
        num_3 = (r * c / 2) - num_4 - 2
        num_2 = 2

        ans = worker(num_4, num_3, num_2, tot, rest)
    else:
        num_4 = ((c-2) * (r-2) + 1) / 2
        num_3 = (r * c + 1) / 2 - num_4 - 4
        num_2 = 4

        ans = worker(num_4, num_3, num_2, tot, rest)


        num_4 = ((c-2) * (r-2) - 1) / 2
        num_3 = (r * c - 1) / 2 - num_4
        num_2 = 0

        ans2 = worker(num_4, num_3, num_2, tot, rest)

        if ans2 < ans:
            ans = ans2
    print "Case #%d:" % C, ans
