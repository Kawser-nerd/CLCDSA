N = int(input())
d_ok = []
ans = 0
for _ in range(N):
    x = int(input())
    if x % 10:
        d_ok += [x]
    ans += x
d_ok.sort()
if ans % 10 == 0:
    if len(d_ok):
        ans -= d_ok[0]
    else:
        ans = 0
print(ans)