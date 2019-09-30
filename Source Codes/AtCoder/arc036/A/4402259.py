N, K = map(int, input().split())
L = [int(input()) for _ in range(N)]

res = -1

for i in range(2, N):
    if L[i-2] + L[i-1] + L[i] <  K:
        res = i + 1
        break
        
print(res)