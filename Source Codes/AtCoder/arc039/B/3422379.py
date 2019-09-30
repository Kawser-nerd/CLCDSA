from math import factorial

N, K = map(int, input().split())
if N <= K:
    m = K % N
    print(factorial(N) // factorial(N-m) // factorial(m) % (10**9+7))
else:
    print(factorial(N+K-1) // factorial(N-1) // factorial(K) % (10**9+7))