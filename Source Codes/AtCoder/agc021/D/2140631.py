def solve(s, k):
    n = len(s)
    if k >= n // 2:
        return n
    dpp = [[1] * (k + 1), [0] * (k + 1)]
    for r in range(1, n):
        dpc = [[0] * (k + 1) for _ in range(r + 2)]
        dpc[r] = [1] * (k + 1)
        for l in range(r - 1, -1, -1):
            dpl, dpl1 = dpc[l], dpp[l + 1]
            if s[l] == s[r]:
                dpc[l] = [c + 2 for c in dpl1]
            else:
                dppl, dpcl1 = dpp[l], dpc[l + 1]
                dpl[0] = max(dppl[0], dpcl1[0])
                for p in range(1, k + 1):
                    dpl[p] = max(dppl[p], dpcl1[p], dpl1[p - 1] + 2)
        dpp = dpc

    return dpp[0][k]


print(solve(input(), int(input())))