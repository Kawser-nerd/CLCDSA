A, B, C, X, Y = map(int, input().split())

print(min([
            2*C*X + B*max(Y-X, 0),
            2*C*Y + A*max(X-Y, 0),
            A*X + B*Y,
            ]))