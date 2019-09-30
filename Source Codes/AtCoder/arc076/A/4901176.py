import math

N, M = map(int, input().split())

if N == M:
    print((2 * math.factorial(N) * math.factorial(M)) % (10 ** 9 + 7))
elif N == M + 1 or N + 1 == M:
    print((math.factorial(N) * math.factorial(M))% (10 ** 9 + 7))
else:
    print(0)