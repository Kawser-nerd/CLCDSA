N = int(input())
A = [int(a) for a in input().split()]

print(*([A[i] for i in range(N-1,-1,-2)]+[A[i] for i in range(N%2,N,2)]))