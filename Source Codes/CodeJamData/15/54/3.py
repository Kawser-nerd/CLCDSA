tc = int(input().strip())

for t in range(tc):
    n = int(input().strip())
    v = [int(x) for x in input().split()]
    c = [int(x) for x in input().split()]

    cnt = sum(c)
    c[0] -= 1
    midx = 0

    res = []

    while cnt > 2:
        while c[midx] == 0:
            midx += 1
        d = v[midx] - v[0]
        #print(d)
        res.append(d)
        if d == 0:
            for i in range(n):
                c[i] = c[i] // 2
        else:
            tosub = {d: c[0] + 1}
            for i in range(1, n):
                c[i] -= tosub.get(v[i], 0)
                tosub[v[i] + d] = c[i]
        cnt /= 2
        #print(" ".join(str(c[i]) for i in range(n)))
        #print(tosub)

    while c[midx] == 0:
        midx += 1

    if v[0] == 0:
        res.append(v[midx])
    else:
        res.append(v[0])

    print("Case #%d: %s" % (t+1, " ".join(str(x) for x in sorted(res))))

