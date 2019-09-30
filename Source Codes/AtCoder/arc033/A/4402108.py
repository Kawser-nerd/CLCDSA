N = int(input())

res = 0
for i in range(N):
    for j in range(i, N):
        res += 1
        
print(res)