N, K = map(int, input().split())

res = 0
    
for b in range(1, N + 1):
    res += max(b - K, 0) * (N  // b)
    res += max(N % b - K + 1, 0)
 
if K == 0:
    res -= N
print(res)