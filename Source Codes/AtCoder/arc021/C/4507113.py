import sys

K = int(input())
N = int(input())
a = sorted(tuple(map(int, l.split())) for l in sys.stdin)

ok, ng = 10**12, 0
ans = 0
while ok-ng > 1:
    mid = (ok+ng) // 2
    count = 0

    for a1, d in a:
        if a1 <= mid:
            # an = a1 + d(n-1) < mid
            count += (mid + d - a1) // d
        else:
            break

    if count >= K:
        ok = mid
    else:
        ng = mid


ans, count = 0, 0
for a1, d in a:
    if a1 <= ok:
        n = (ok + d - a1) // d
        if a1 + d*(n-1) == ok:
            n -= 1
        count += n
        # S = 1/2 * n * (2*a1 + (n-1)d)
        ans += (n * (2*a1 + (n-1)*d)) // 2
if count < K:
    ans += (K - count) * ok

print(ans)