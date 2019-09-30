def inpl(): return list(map(int, input().split()))
L = int(input())
B = [int(input()) for _ in range(L)]

A = [0]*L
for i in range(1, L):
    A[i] = A[i-1] ^ B[i-1]

if A[-1] ^ B[-1] == A[0]:
    print(*A, sep="\n")
else:
    print(-1)