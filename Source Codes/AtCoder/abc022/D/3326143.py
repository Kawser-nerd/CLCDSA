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

max_distance_A2 = 0
max_distance_B2 = 0
for a in A:
    distance_2 = (a.x - A_w.x)**2 + (a.y - A_w.y)**2
    if distance_2 > max_distance_A2:
        max_distance_A2 = distance_2
for b in B:
    distance_2 = (b.x - B_w.x)**2 + (b.y - B_w.y)**2
    if distance_2 > max_distance_B2:
        max_distance_B2 = distance_2

print(sqrt(max_distance_B2 / max_distance_A2))