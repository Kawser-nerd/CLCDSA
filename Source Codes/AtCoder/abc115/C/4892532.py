N, K = list(map(int, input().split()))
H = sorted([int(input()) for _ in range(N)])

min_h = 1e15
for i in range(N-K+1):
    tmp = H[i+K-1] - H[i]
    if tmp < min_h:
        min_h = tmp
print(min_h)