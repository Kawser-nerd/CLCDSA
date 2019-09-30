import bisect


def soin(n):
    re = []
    while n > 1:
        for i in range(2, int(n ** 0.5) + 1):
            if n % i == 0:
                re += [i]
                n //= i
                break
        else:
            re += [n]
            n = 0
    return re


n = int(input())
sol = []
for i in range(2, n + 1):
    sol += soin(i)

sisu = []
for sk in set(sol):
    sisu += [sol.count(sk)]

sisu.sort()
lsi = len(sisu)
c74 = lsi - bisect.bisect_left(sisu, 74)
c24 = lsi - bisect.bisect_left(sisu, 24)
c14 = lsi - bisect.bisect_left(sisu, 14)
c4 = lsi - bisect.bisect_left(sisu, 4)
c2 = lsi - bisect.bisect_left(sisu, 2)

c24_2 = c24 * (c2 - 1)
c14_4 = c14 * (c4 - 1)
c4_4_2 = c4 * (c4 - 1) * (c2 - 2) // 2

print(c74 + c24_2 + c14_4 + c4_4_2)