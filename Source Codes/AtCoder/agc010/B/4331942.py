N = int(input())
A = list(map(int, input().split()))
s = sum(A)
K = s // (N * (N + 1) // 2)
if N == 1:
    print("YES")
    exit()
if s % (N * (N + 1) // 2) != 0:
    print("NO")
    exit()
d = [0] * (N - 1)
for i in range(N - 1):
    d[i] = A[i + 1] - A[i] - K

for i in range(N - 1):
    if d[i] > 0 or abs(d[i]) % N != 0:
        print("NO")
        exit()
print("YES")