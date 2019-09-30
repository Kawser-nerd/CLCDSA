N = int(input())
A = [int(a) for a in input().split()]
A.sort()
mid = A[-1]/2
Aj = A[0]
for i in range(1, N-1):
    if abs(A[i] - mid) < abs(Aj - mid):
        Aj = A[i]
print(A[-1], Aj)