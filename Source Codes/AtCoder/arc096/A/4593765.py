A, B, C, X, Y = [int(x) for x in input().split()]
maxAB = max(X, Y)
min = 2*maxAB*C+1

for i in range(maxAB+1):
    numA = max(X-i, 0)
    numB = max(Y-i, 0)
    value = numA*A+numB*B+2*i*C
    if value < min:
        min = value

print(min)