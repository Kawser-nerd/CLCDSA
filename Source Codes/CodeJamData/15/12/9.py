tc = int(input().strip())

for t in range(tc):
    b, n = tuple(int(x) for x in input().strip().split())
    m = list(int(x) for x in input().strip().split())

    l, r = -1, n * min(m)
    lv = 0

    while l + 1 < r:
        c = (l + r) // 2
        v = sum(c // a + 1 for a in m)
        if v < n:
            l = c
            lv = v
        else:
            r = c
    idx = n - lv - 1

    ans = list(i+1 for i in range(b) if r % m[i] == 0)[idx]

    print("Case #%d: %d" % (t+1, ans))
