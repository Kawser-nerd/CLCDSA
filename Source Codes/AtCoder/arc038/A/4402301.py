N = int(input())
L = list(map(int, input().split()))
L .sort()

res = 0
for i in range(N):
    if i%2 == 0:
        res += L[N - i - 1]
        
print(res)