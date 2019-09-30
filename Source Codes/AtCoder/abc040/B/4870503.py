from math import floor

n = int(input())

ans = 100005
for w in range(1, n+1):
    h = floor(n/w)
    x = abs(w-h) + (n - w*h)
    if x < ans:
        ans = x

print(ans)