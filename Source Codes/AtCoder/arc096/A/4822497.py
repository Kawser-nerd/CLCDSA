A, B, C, X, Y = map(int, input().split())

if X < Y:
    print(min(2*C*X + (Y - X) * B, X * A + Y * B, 2*C*Y))
else:
    print(min(2*C*Y + (X - Y) * A, X * A + Y * B, 2*C*X))