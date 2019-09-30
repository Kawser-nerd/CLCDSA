import math
N = int(input())
A = list(map(int, input().split()))
A.sort()

def combinations_count(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

if len(A) == 2:
    print(A[1])
    print(A[0])

half = A[-1] / 2
for i in range(N-2):
    if abs(A[i]-half) >= abs(A[i+1]-half) <= abs(A[i+2]-half):
            print(A[-1])
            print(A[i+1])
            exit()