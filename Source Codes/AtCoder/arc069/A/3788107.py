a,b = map(int,input().split(" "))
count = 0
if a <= b // 2:
    count += a
    b -= a * 2
    count += b // 4
else:
    count += b // 2
    b -= (b // 2) * 2
    count += b // 4
print(count)