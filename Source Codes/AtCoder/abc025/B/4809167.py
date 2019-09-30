N, A, B = map(int, input().split())
ans = 0
for _ in range(N):
    s, d = input().split()
    d = min(B, max(A, int(d)))
    if s == "East":
        d *= -1
    ans += d

if ans == 0:
    print("0")
elif ans < 0:
    print("East", -ans)
else:
    print("West", ans)