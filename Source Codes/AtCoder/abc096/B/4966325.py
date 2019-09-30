#094 B
A = [int(j) for j in input().split()]
K=int(input())
A.sort()
print(A[2]*((2**K)-1)+sum(A))