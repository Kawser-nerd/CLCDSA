T = int(input())

for case in range(1, T + 1):
    N = int(input())
    line = input()
    t = line.split()
    a = [[chr(ord('A') + i), int(t[i])] for i in range(len(t))]
    tot = sum([x[1] for x in a])
    res = []
    while tot > 0:
        a.sort(reverse=True, key=lambda x: x[1])
        if 2 * a[1][1] <= tot - 1:
            a[0][1] -= 1
            tot -= 1
            res.append(a[0][0])
        else:
            a[0][1] -= 1
            a[1][1] -= 1
            tot -= 2
            res.append(a[0][0] + a[1][0])
    print("Case #{0}: {1}".format(case, ' '.join(res)))

