n = int(input())
k = int(input())
res = 1
for i in range(n):
    res = min(res*2,res+k)
print(res)