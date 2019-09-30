a = int(input())
i = a * a
l = i
r = i + 2 * a
while l <= r:
    i = l
    l = (l + 99) // 100
    r = r // 100
print(i)