# coding: utf-8

II = lambda: int(input())
MI = lambda: map(int, input().split())


def sumcnt(values):
    sc = [0] * (50 * 50 + 1)
    sc[0] = 1
    max_sc = 0
    for v in values:
        for i in range(max_sc, -1, -1):
            sc[i + v] += sc[i]
        max_sc += v
    return sc, max_sc


def main():
    N, A = MI()
    ds = [x-A for x in MI()]

    count0 = 0
    dp, dm = [], []
    for d in ds:
        if d == 0: count0 += 1
        elif d > 0: dp.append(d)
        else: dm.append(-d)
    dp.sort()
    dm.sort()

    scp, scpmax = sumcnt(dp)
    scm, scmmax = sumcnt(dm)

    ans = 0
    for i in range(1, min(scpmax, scmmax) + 1):
        ans += scp[i] * scm[i]
    ans = ans * (2**count0) + 2**count0 - 1
    return ans


if __name__ == "__main__":
    print(main())