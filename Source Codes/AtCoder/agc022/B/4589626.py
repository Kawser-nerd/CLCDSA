n = int(input())

if n == 3:
    print(2, 5, 63)
elif n == 4:
    print(2, 5, 20, 63)
elif n == 5:
    print(2, 5, 20, 30, 63)
else:
    a = []
    count = 0
    for i in range(2, 30001):
        if i % 2 == 0 or i % 3 == 0:
            a.append(i)
            count += 1
        if count == n:
            break
    sum_a = sum(a)
    if sum_a % 6 == 0:
        print(*a)
    elif sum_a % 6 == 2:
        a[4] = 30000
        print(*a)
    elif sum_a % 6 == 3:
        a[5] = 30000
        print(*a)
    else:
        a[5] = 29998
        print(*a)