N = int(input())
A = list(map(int, input().split()))

max_index = 1
max_abs = abs(A[0])
if A[0] >= 0:
    pos = True
else:
    pos = False

for i in range(1, N):
    if max_abs < abs(A[i]):
        max_abs = abs(A[i])
        max_index = i + 1
        if A[i] >= 0:
            pos = True
        else:
            pos = False

if pos:
    print(2*N - 2)
    for n in range(N):
        if max_index - 1 != n:
            print(max_index, n+1)
    for n in range(2, N+1):
        print(n-1, n)
else:
    print(2 * N - 2)
    for n in range(N):
        if max_index - 1 != n:
            print(max_index, n + 1)
    for n in reversed(range(2, N + 1)):
        print(n, n-1)