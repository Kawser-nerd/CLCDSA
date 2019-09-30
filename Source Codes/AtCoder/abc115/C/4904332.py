N, K = map(int, input().split())
h = []
for i in range(N):
    h.append(int(input()))
    
h.sort()

min = 10**9
for i in range(N-K+1):
    if h[i+K-1] - h[i] < min:
        min = h[i+K-1] - h[i]

print(min)