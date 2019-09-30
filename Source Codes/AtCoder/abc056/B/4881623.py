W, a, b = map(int, input().split())

if a <= b:
    aw = a + W
    ans = max(b - aw, 0)
else:
    bw = b + W
    ans = max(a - bw, 0)

print(ans)