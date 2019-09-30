A = list(map(int, input().split()))
M = max(A)
S = sum(A)
M += M % 2 != S % 2
print((3 * M - S) // 2)