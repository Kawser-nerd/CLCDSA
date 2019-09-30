n = int(input())
ans = 0
for i in range(int((n-1)**0.5), int(n**0.5)+1):
    ans = max(ans, i ** 2)

print(ans)