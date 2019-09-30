import math
import sys

input = sys.stdin.readline
N = int(input())
Ax, Ay = [0] * N, [0] * N
for i in range(N):
    Ax[i], Ay[i] = map(int, input().split())
Bx, By = [0] * N, [0] * N
for i in range(N):
    Bx[i], By[i] = map(int, input().split())


def calc_diff(X, Y):
    cx, cy = sum(X) / N, sum(Y) / N
    d = 0
    for x, y in zip(X, Y):
        d += math.sqrt((cx - x)**2 + (cy - y)**2)
    return d / N


a, b = calc_diff(Ax, Ay), calc_diff(Bx, By)
print(b / a)