#4
n = int(input())
ans = 100
for i in range(n):
    temp = int(input())
    ans = min(ans, temp)
print(ans)