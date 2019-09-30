N = int(input())
ans = 0
for i in range(N):
    a, b, c, d, e = map(int, input().split())
    tmp = a + b + c + d + e * 110 / 900
    ans = max(ans, tmp)
    
print(ans)