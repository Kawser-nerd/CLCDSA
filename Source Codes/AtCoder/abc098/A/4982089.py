A, B = map(int, input().split())

max = -1000
if A + B > max:
    max = A + B
if A - B > max:
    max = A - B
if A * B > max:
    max = A * B
print(max)