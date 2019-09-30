def crossing(A, B, X, Y):
  AB = [B[0] - A[0], B[1] - A[1]]
  AX = [X[0] - A[0], X[1] - A[1]]
  AY = [Y[0] - A[0], Y[1] - A[1]]
  S0 = (AB[0] * AX[1] - AB[1] * AX[0]) * (AB[0] * AY[1] - AB[1] * AY[0])
  XY = [Y[0] - X[0], Y[1] - X[1]]
  XA = [A[0] - X[0], A[1] - X[1]]
  XB = [B[0] - X[0], B[1] - X[1]]
  S1 = (XY[0] * XA[1] - XY[1] * XA[0]) * (XY[0] * XB[1] - XY[1] * XB[0])
  return 1 if S0 < 0 and S1 < 0 else 0
ax, ay, bx, by = map(int, input().split())
N = int(input())
XY = [0] * (N + 1)
for i in range(N):
  x, y = map(int, input().split())
  XY[i] = [x, y]
XY[-1] = XY[0]
cross = 0
for i in range(N):
  cross += crossing([ax, ay], [bx, by], XY[i], XY[i + 1])
print(cross // 2 + 1)