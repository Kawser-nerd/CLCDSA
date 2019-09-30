C1 = list(map(int, input().split()))
C2 = list(map(int, input().split()))
C3 = list(map(int, input().split()))

C = [C1, C2, C3]
A = [0] * 3
B = [0] * 3

B = C1
A[1] = C2[0] - B[0]
A[2] = C3[0] - B[0]
flg = True
for i, a in enumerate(A):
    for j, b in enumerate(B):
        if C[i][j] != a + b:
            flg = False

if flg is True:
    print("Yes")
else:
    print("No")