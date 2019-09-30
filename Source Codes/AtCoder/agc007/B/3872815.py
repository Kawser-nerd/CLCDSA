N = int(input())
P = list(map(int,input().split()))
A = [45678 * i for i in range(1, N + 1)]
B = A[::-1]
for i, p in enumerate(P):
    A[p - 1] += i
    B[p - 1] += i
print(*A)
print(*B)