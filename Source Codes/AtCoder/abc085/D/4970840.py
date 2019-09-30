n, h = map(int, input().split())
amax = 0
bl = []
for i in range(n):
    a, b = map(int, input().split())
    amax = max(amax, a)
    bl.append(b)
bl.sort()
bl.reverse()

ans = 0
for i in range(n):
    if h <= 0:
        break
    if bl[i] <= amax:
        break
    ans += 1
    h -= bl[i]
if h > 0:
    ans += h // amax
    h -= (h // amax) * amax
if h > 0:
    ans += 1

print(ans)