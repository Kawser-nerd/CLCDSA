num_testcases = int(input())

for testcase_num in range(1, num_testcases + 1):
    n, p = tuple(int(x) for x in input().split())
    d = [0] * p
    for x in input().split():
        d[int(x) % p] += 1
    res = d[0]
    if p == 2:
        res += d[1] // 2 + d[1] % 2
    elif p == 3:
        mini = min(d[1], d[2])
        maxi = max(d[1], d[2])
        res += mini + (maxi - mini) // 3 + (1 if (maxi - mini) % 3 else 0)
    elif p == 4:
        mini = min(d[1], d[3])
        maxi = max(d[1], d[3])
        res += mini + d[2] // 2
        if d[2] % 2 == 0:
            res += (maxi - mini) // 4 + (1 if (maxi - mini) % 4 else 0)
        else:
            a = max(maxi - mini - 2, 0)
            res += 1 + a // 4 + (1 if a % 4 else 0)
    print("Case #%d: %s" % (testcase_num, res))
