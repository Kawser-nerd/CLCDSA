#094 B
A = [int(j) for j in input().split()]
K=int(input())
for i in range(K):
    A.sort()
    A[2]=A[2]*2
print(sum(A))