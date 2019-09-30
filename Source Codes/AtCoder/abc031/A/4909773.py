A, D = map(int, input().split())

if A <= D:
    A += 1
else:
    D += 1

print(int(A * D))