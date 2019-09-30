import sys
from itertools import accumulate

circumference, n = map(int, input().split())
lll = list(map(int, sys.stdin.readlines()))
rrr = [circumference - l for l in lll]
rrr.reverse()
lll = [0] + lll
rrr = [0] + rrr
acc_l = list(accumulate(lll))
acc_r = list(accumulate(rrr))

ans = max(lll[-1], rrr[-1])
for take_l in range(1, n):
    take_r = n - take_l

    # l last
    tmp_l = lll[take_l] + 2 * (acc_l[take_l - 1] + acc_r[take_r])
    # r last
    tmp_r = rrr[take_r] + 2 * (acc_r[take_r - 1] + acc_l[take_l])

    if take_l < take_r:
        tmp_l -= 2 * acc_r[take_r - take_l]
        tmp_r -= 2 * acc_r[take_r - 1 - take_l]
    elif take_l > take_r:
        tmp_l -= 2 * acc_l[take_l - 1 - take_r]
        tmp_r -= 2 * acc_l[take_l - take_r]

    ans = max(ans, tmp_l, tmp_r)
print(ans)