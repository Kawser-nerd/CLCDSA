n, h = map(int, input().split())
a, b, c, d, e = map(int, input().split())

ans = float('inf')
for i in range(n + 1):
    j = max(0, (- h - b * i + e * (n - i)) // (d + e) + 1)
    ans = min(ans, a * i + c * j)
    #print(i, j, n - i - j, ans)
            
print(ans)