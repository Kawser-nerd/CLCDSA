from math import sqrt
N = int(input())
class P:
    def __init__(self, x, y):
        self.x = x
        self.y = y

A = [0] * N
ax_sum, ay_sum = 0, 0
for i in range(N):
    x, y = [int(x) for x in input().split()]
    ax_sum += x
    ay_sum += y
    A[i] = P(x, y)

B = [0] * N
bx_sum, by_sum = 0, 0
for i in range(N):
    x, y = [int(x) for x in input().split()]
    bx_sum += x
    by_sum += y
    B[i] = P(x, y)

A_w = P(ax_sum / N, ay_sum / N)
B_w = P(bx_sum / N, by_sum / N)

max_distance_A = 0
max_distance_B = 0
for a in A:
    distance = sqrt((a.x - A_w.x)**2 + (a.y - A_w.y)**2)
    if distance > max_distance_A:
        max_distance_A = distance
for b in B:
    distance = sqrt((b.x - B_w.x)**2 + (b.y - B_w.y)**2)
    if distance > max_distance_B:
        max_distance_B = distance

print(max_distance_B / max_distance_A)