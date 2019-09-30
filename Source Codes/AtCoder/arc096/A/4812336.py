A, B, C, X, Y = map(int, input().split())

cost = 0
if (A+B)/2 > C:
    cost = 2*C*min(X, Y)
    if X > Y:
        X = X - Y
        if A > 2*C:
            cost += 2*C*X
        else:
            cost += A*X
    else:
        Y = Y - X
        if B > 2*C:
            cost += 2*C*Y
        else:
            cost += B*Y
else:
    cost = A*X + B*Y
print(cost)