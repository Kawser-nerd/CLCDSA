from math import ceil
N, K = map(int, input().split())
A = list(map(int, input().split()))
print(ceil((N - 1) / (K - 1)))