n, x = map(int,input().split())
a = list(map(int, input().split()))

a.sort()
count = 0
for ai in a:
    if x >= ai:
        x -= ai
        count += 1
    else:
        x = 0
if x > 0:
    count -= 1

print(count)