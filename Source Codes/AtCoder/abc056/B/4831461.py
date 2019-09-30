w, a, b = map(int, input().split())

if a <= b:
    aw = a + w
    ans = max(b - aw, 0)
else:
    bw = b + w
    ans = max(a - bw, 0)

print(ans)