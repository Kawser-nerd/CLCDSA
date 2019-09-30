t = int(input())
for i in range(t):
    k,c,s = map(int, input().split())
    if c * s < k:
        print("Case #%d: IMPOSSIBLE" % (i + 1))
        continue
    pos = []
    x = 0
    while x < k:
        a = 0
        for _ in range(c):
            a *= k
            a += min(x, k - 1)
            if x < k:
                x += 1
        pos.append(str(a + 1))
    print("Case #%d: %s" % (i + 1, " ".join(pos)))
