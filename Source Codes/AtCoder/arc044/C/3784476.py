import sys
from collections import defaultdict

W, H, Q = map(int, input().split())
v_beam, h_beam = defaultdict(list), defaultdict(list)
inf = float("inf")
for t, d, x in (map(int, l.split()) for l in sys.stdin):
    if d == 0:
        v_beam[t].append(x)
    else:
        h_beam[t].append(x)

dpx, dpy = [0]*(W+2), [0]*(H+2)
for dp, beam in ((dpx, v_beam), (dpy, h_beam)):
    for _, a in sorted(sorted(beam.items())):
        a.sort()
        a += [-1]
        prev = a[0]-1
        prev_v = inf
        for i, j in zip(a, a[1:]):
            if prev_v > dp[i]+i-prev:
                prev_v = dp[i]+i-prev
            if dp[i+1] > dp[i]+1:
                dp[i+1] = dp[i]+1
            dp[i] = inf
            if i+1 != j:
                if dp[prev] > prev_v:
                    dp[prev] = prev_v
                prev = j-1
                prev_v = inf

ans = min(dpx[1:-1]) + min(dpy[1:-1])
print(ans if ans < inf else -1)