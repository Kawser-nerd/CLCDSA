N = int(input())
A = []
Ax, Ay = 0, 0
B = []
Bx, By = 0, 0
for i in range(N):
    x, y = map(int, input().split())
    A.append((x, y))
    Ax += x
    Ay += y
for i in range(N):
    x, y = map(int, input().split())
    B.append((x, y))
    Bx += x
    By += y

Ax, Ay = Ax / N, Ay / N
Bx, By = Bx / N, By / N

R1 = 0
for i in range(N):
    R1 = max(R1, ((A[i][0] - Ax) ** 2 + (A[i][1] - Ay) ** 2) ** 0.5)

R2 = 0
for i in range(N):
    R2 = max(R2, ((B[i][0] - Bx) ** 2 + (B[i][1] - By) ** 2) ** 0.5)

print(R2 / R1)