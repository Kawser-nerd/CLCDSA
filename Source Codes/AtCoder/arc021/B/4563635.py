import sys
L = int(input())
B = [int(sys.stdin.readline()) for _ in range(L)]

A = [0]*L
for i in range(1, L):
    A[i] = A[i-1] ^ B[i-1]
if B[-1]^A[-1]:
    print(-1)
else:
    for a in A:
        print(a)