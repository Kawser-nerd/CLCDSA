import sys
from operator import itemgetter
N = int(input())
# ????????
sorted_l = sorted((tuple(map(int, l.split())) for l in sys.stdin), reverse=True)
# ????????
sorted_r = sorted(sorted_l, key=itemgetter(1))

pos1, ans1 = 0, 0
pos2, ans2 = 0, 0
for i, j in enumerate(i//2 for i in range(N)):
    if i % 2 == 0:
        dist1, dist2 = max(sorted_l[j][0]-pos1, 0), max(pos2-sorted_r[j][1], 0)
        pos1, ans1 = pos1+dist1, ans1+dist1
        pos2, ans2 = pos2-dist2, ans2+dist2
    else:
        dist1, dist2 = max(pos1-sorted_r[j][1], 0), max(sorted_l[j][0]-pos2, 0)
        pos1, ans1 = pos1-dist1, ans1+dist1
        pos2, ans2 = pos2+dist2, ans2+dist2


print(max(ans1+abs(pos1), ans2+abs(pos2)))