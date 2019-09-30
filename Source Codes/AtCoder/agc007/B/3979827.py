N = int(input())
P = [int(_) - 1 for _ in input().split()]
Q = sorted([(P[i], i) for i in range(N)])

A = [1]
B = [10**9]

for i in range(1, N):
    d = Q[i][1] - Q[i - 1][1]
    if d > 0:
        A += [A[-1] + d + 1]
        B += [B[-1] - 1]
    else:
        A += [A[-1] + 1]
        B += [B[-1] + d - 1]
print(*A, sep=" ")
print(*B, sep=" ")