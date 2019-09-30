x1,y1,x2,y2 = map(int,input().split())
n = int(input())
l=[list(map(int,input().split())) for _ in range(n)]

def check(A, B, X, Y):
  AB = [B[0] - A[0], B[1] - A[1]]
  AX = [X[0] - A[0], X[1] - A[1]]
  AY = [Y[0] - A[0], Y[1] - A[1]]
  S0 = (AB[0] * AX[1] - AB[1] * AX[0]) * (AB[0] * AY[1] - AB[1] * AY[0])
  XY = [Y[0] - X[0], Y[1] - X[1]]
  XA = [A[0] - X[0], A[1] - X[1]]
  XB = [B[0] - X[0], B[1] - X[1]]
  S1 = (XY[0] * XA[1] - XY[1] * XA[0]) * (XY[0] * XB[1] - XY[1] * XB[0])
  return 1 if S0 < 0 and S1 < 0 else 0

crs = 0
for i in range(n):
    i1 = i - 1
    if i1 < 0: i1 = n - 1
    if check([x1,y1],[x2,y2],l[i1],l[i]):
        crs += 1

print(crs // 2 + 1)