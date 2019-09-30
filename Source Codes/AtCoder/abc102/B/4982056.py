#102
N=int(input())
A = [int(j) for j in input().split()]
A.sort()
print(abs(A[N-1]-A[0]))