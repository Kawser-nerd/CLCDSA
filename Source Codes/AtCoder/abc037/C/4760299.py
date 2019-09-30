N, K = list(map(int, input().split()))
A = list(map(int, input().split()))

print(sum([a*min([(i+1), K, N-K+1, (N-i)]) for i,a in enumerate(A)]))