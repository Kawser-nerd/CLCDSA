N, M = list(map(int, input().split()))
A = {}
B = [0] * N
for i in range(N):
    A[i], B[i] = list(map(int, input().split()))
A = sorted(A.items(), key=lambda x:x[1])

ans = 0

for i in range(N):
    if M > B[A[i][0]]:
        ans += A[i][1] * B[A[i][0]]
        M -= B[A[i][0]]
    else:
        ans += A[i][1] * M
        break;
print(ans)