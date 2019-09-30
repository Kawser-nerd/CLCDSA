n = int(input())

l1 = 2
l2 = 1
l3 = 3

if n >= 2:
    for i in range(n - 1):
        t = l1 + l2
        l1 = l2
        l3 = t
        l2 = l3
    print(l3)
else:
    if n == 1:
        print(l2)
    else:
        print(l1)