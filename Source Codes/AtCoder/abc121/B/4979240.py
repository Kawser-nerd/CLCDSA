N, M, C = map(int, input().split())
A = []
cnt = 0
B = list(map(int, input().split()))

for i in range(N):
    A = list(map(int, input().split()))
    if sum(A[j]*B[j] for j in range(M)) + C > 0:
        cnt += 1

print(cnt)