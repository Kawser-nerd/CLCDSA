a, b, c, k = map(int, input().split())
s, t = map(int, input().split())

ans = a * s + t * b
if (s + t) >= k:
    ans -= (s + t) * c

print(ans)