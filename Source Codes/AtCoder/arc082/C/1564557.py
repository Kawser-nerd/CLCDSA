# E
from collections import Counter

N = int(input())
xy_list = [list(map(int, input().split())) for _ in range(N)]

M = 998244353

res = pow(2, N, M)
# 0 points
res -= 1
# 1 points
res -= N

# all lines
line_cnt = [0]*(N+1)

for i in range(N):
    xi, yi = xy_list[i]
    angle_list = []
    for j in range(N):
        xj, yj = xy_list[j]
        if xj != xi:
            angle_list.append((yj-yi)/(xj-xi))
        elif yj != yi:
            angle_list.append(10000.0)
        
    # count points in same line
    cnt_i = Counter(angle_list)
    for k in cnt_i.values():
        line_cnt[k+1] += 1

for i in range(2, N+1):
    cnt = line_cnt[i] // i
    res -= cnt*(pow(2, i, M)-i-1)

res = res % M
print(res)