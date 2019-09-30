from bisect import bisect_left

N = int(input())
items = []
for _ in range(N):
    items.append(tuple(map(int, input().split())))

items = sorted(items, key=lambda x: (x[1], -x[0]))

ans = [float("inf")]

for w, h in items:
    i = bisect_left(ans, w)
    if i >= len(ans):
        ans.append(w)
    else:
        ans[i] = w
print(len(ans))