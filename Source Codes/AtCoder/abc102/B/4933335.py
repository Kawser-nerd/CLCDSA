N = int(input())
A = list(map(int, input().split()))
A = sorted(A)
print(A[N-1]-A[0])