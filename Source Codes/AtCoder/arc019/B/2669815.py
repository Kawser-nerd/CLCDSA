from math import ceil

A = input()
N = len(A)
X = 0
for i in range(ceil(N / 2)):
    if A[i] != A[-i-1]:
        X += 1

if X >= 2:
    print(25*N)
elif X == 0:
    if N % 2 == 0:
        print(25*N)
    else:
        print(25*(N-1))
else:
    print(25*(N-2) + 48)