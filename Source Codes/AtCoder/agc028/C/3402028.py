N = int(input())
A = []
B = []
for i in range(N):
    a, b = map(int, input().split())
    A += [a]
    B += [b]
s1 = sum(A)
s2 = sum(B)
C = A + B
C.sort()
s3 = sum(C[:N])
s4 = sum(C[N:])
check = 1
m1 = C[N-1]
m2 = C[N-2]
for i in range(N):
    a = min(A[i], B[i])
    b = max(A[i], B[i])
    if b < m1:
        check = 0
        break
    elif b == m1 and a != b:
        check = 0
        break
    elif a < m1:
        s4 = min(s4, s3 - m1 + b)
    elif a == m1:
        s4 = min(s4, s3 - m2 + b)
if check == 0:
    print(min(s1, s2, s3))
else:
    print(min(s1, s2, s4))