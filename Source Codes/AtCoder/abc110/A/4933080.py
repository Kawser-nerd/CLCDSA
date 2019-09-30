A = list(map(int,input().split()))

A = sorted(A)
B = str(A[2]) + str(A[1])
B = int(B)
print(B+A[0])