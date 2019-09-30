import math

N,K = (int(i) for i in input().split())

if K < N:
    ans = math.factorial(N+K-1) // (math.factorial(N+K-1-K) * math.factorial(K)) %(10**9 + 7)
else:    
    ans = math.factorial(N) // (math.factorial(N - K%N) * math.factorial(K%N)) %(10**9 + 7)

print(ans)