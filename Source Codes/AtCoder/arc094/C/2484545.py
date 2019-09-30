N = int(input())
A, B = [], []
for i in range(N):
    a, b = map(int, input().split())
    A.append(a)
    B.append(b)
M = sum(A)

for i in range(N):
    if A[i] <= B[i]:
        A[i] = 0
        B[i] -= A[i]

ne = M
for i in range(N):
    if A[i] != 0 and B[i] < ne:
        ne = B[i]
print(M - ne)