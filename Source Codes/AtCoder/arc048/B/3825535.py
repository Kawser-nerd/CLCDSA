from bisect import bisect_left as bl, bisect_right as br
from functools import lru_cache

N = int(input())
RH = [list(map(int, input().split(" "))) for _ in range(N)]

R, H = zip(*sorted(RH))

@lru_cache(maxsize=None)
def hand_battle(l, r, h):
    a = [0]+[br(H[rate_l:rate_r], i) for i in range(1, 4)]
    gcp = [a[i+1]-a[i] for i in range(3)]
    return gcp

for r, h in RH:
    rate_l = bl(R, r)
    rate_r = br(R, r)
    gcp = hand_battle(rate_l, rate_r, h)
    win = rate_l+gcp[h%3]
    lose = N-rate_r+gcp[(h-2)%3]
    draw = N-win-lose-1
    print(win, lose, draw)
    # print(rate_l, "_", rate_r, H[rate_l:rate_r])
    # print(gcp)