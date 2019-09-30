from math import factorial


def perm(r, c):
    return factorial(r) // factorial(r - c)


def comb(r, c):
    return perm(r, c) // factorial(c)


N, P = map(int, input().split())
a = list(map(int, input().split()))
a = list(map(lambda x: x % 2, a))
a = list(sorted(a))

cnt_0 = a.count(0)
cnt_1 = a.count(1)

ans = 0
if P == 0:
    for j in range(0, cnt_1 + 1, 2):
        ans += comb(cnt_1, j) * (2 ** cnt_0)
else:
    # P == 1
    for j in range(1, cnt_1 + 1, 2):
        ans += comb(cnt_1, j) * (2 ** cnt_0)
print(ans)