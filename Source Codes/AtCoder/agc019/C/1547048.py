import math
import bisect

def get_lis(S):
    dp = [float('inf')] * len(S)
    for i, (x, y) in enumerate(S):
        a = S[i][1]
        j = bisect.bisect_right(dp, a)
        dp[j] = a
    return bisect.bisect_left(dp, float('inf'))

x_1, y_1, x_2, y_2 = map(int, input().split())
N = int(input())

if x_1 <= x_2:
    x_s = x_1
    y_s = y_1
    x_t = x_2
    y_t = y_2
else:
    x_s = x_2
    y_s = y_2
    x_t = x_1
    y_t = y_1

x_min = min(x_1, x_2)
x_max = max(x_1, x_2)
y_min = min(y_1, y_2)
y_max = max(y_1, y_2)

S = []
for i in range(N):
    X, Y = map(int, input().split())
    if X < x_min or X > x_max or Y < y_min or Y > y_max:
        continue
    S.append((X, Y))

dist = 0
s_num = len(S)

S.sort()
if y_s > y_t:
    S.reverse()
    start_y = y_t
    end_y = y_s
else:
    start_y = y_s
    end_y = y_t

round_count = get_lis(S)
dist = (abs(x_t - x_s) + abs(y_t - y_s)) * 100 + (math.pi * 20 / 4 - 20) * round_count

if min(abs(x_t - x_s), abs(y_t - y_s)) + 1 == round_count:
    dist += math.pi * 5

print(dist)