A, B, C, X, Y = map(int, input().split())

totalA1 = A * X
totalA2 = C * X * 2
totalB1 = B * Y
totalB2 = C * Y * 2

totalAB = A * X + B * Y

totalAC = C * Y * 2
if X > Y:
    totalAC += (X - Y) * A

totalCB = C * X * 2
if Y > X:
    totalCB += (Y - X) * B

totalCC = max(X, Y) * C * 2

print(min(totalAB, totalAC, totalCB, totalCC))