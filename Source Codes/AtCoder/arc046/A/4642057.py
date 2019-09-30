N = int(input()) - 1
A = [int(str(i)*j) for i in range(1,10) for j in range(1,10)]
A.sort()
print(A[N])