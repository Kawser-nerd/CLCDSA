x = int(input())
l = [1]
for i in range(2, x):
    n = 2
    while i ** n <= x:
        l.append(i ** n)
        n += 1
print(max(l))