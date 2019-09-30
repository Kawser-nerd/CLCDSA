N, x = map(int, input().split())
a = list(map(int, input().split()))
count = 0
a.sort()
for i in range(N):
    if x >= a[i]:
        count += 1
        x -= a[i]
    else:
        break
else:
    if x != 0:
        count -= 1
print(count)