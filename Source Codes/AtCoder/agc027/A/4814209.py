N, x = map(int, input().split())
a = sorted(int(x) for x in input().split())
ans = 0
for ai in a:
    x -= ai
    if x < 0:
        break
    ans += 1
if 0 < x:
    ans -= 1
print(ans)