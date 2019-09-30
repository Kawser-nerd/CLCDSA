N, M, C = map(int, input().split())
B = list(map(int, input().split()))

counter = 0
for i in range(N):
    s = C
    A = list(map(int, input().split()))
    for j in range(M):
        s += A[j] * B[j]
    if s > 0:
        counter += 1
print(counter)