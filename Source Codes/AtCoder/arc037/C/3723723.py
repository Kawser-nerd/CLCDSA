from bisect import bisect_right

N, K = map(int, input().split())
a = sorted(map(int, input().split()))
b = list(map(int, input().split()))

ok, ng = 0, 10**18+1
while ng-ok > 1:
    x = (ok+ng) // 2
    count = sum(bisect_right(a, x//b_n) for b_n in b)

    if count < K:
        ok = x
    else:
        ng = x

print(ok+1)