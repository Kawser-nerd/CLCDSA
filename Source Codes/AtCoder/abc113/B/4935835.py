n = int(input())
t, a = map(int, input().split())
hs = list(map(int, input().split()))
best_sub = 100000
ans = -1
for i, h in enumerate(hs):
    t_ = t - h * 0.006
    if abs(a - t_) < best_sub:
        best_sub = abs(a - t_)
        ans = i + 1
print(ans)