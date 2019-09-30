A, B, C = map(int, input().split())

if B < C:
    tmp = B
    B = C
    C = tmp
if A < B:
    tmp = A
    A = B
    B = tmp
print((A * 10) + B + C)