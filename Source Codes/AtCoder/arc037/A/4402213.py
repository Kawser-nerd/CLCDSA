N = int(input())
L = list(map(int, input().split()))

res = 0
for i in range(N):
    if L[i] >= 80:
        pass
    else:
        res += 80 - L[i]
    
print(res)