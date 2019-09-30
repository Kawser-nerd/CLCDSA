N, x = map(int, input().split())
an = map(int, input().split())

count = 0
san = sorted(an)
for a in san:
    x -= a
    if x < 0:
        break
    count += 1
if x > 0:
    count -= 1

print(count)