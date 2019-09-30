A = [int(i) for i in input().split()]
A.sort()
res = 0
for i in range(1, len(A)):
    res += A[i] - A[i-1]
print(res)