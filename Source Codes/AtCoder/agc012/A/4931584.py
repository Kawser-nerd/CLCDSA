N = int(input())
A = list(map(int, input().split()))
A = sorted(A, reverse=True)

total = 0
for i in range(1, 2*N, 2):
    total += A[i]
print(total)