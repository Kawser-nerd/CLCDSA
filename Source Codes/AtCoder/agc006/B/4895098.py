n, x = map(int, input().split())
if x == 1 or x == 2*n-1:
    print("No")
else:
    print("Yes")
    if n == 2:
        print(1)
        print(2)
        print(3)
    else:
        a = [0 for i in range(2*n-1)]
        if x == 2*n-2:
            a[n-3] = x-2
            a[n-2] = x+1
            a[n-1] = x
            a[n] = x-1
        else:
            a[n-3] = x+1
            a[n-2] = x-1
            a[n-1] = x
            a[n] = x+2
        y = 1
        for i in range(2*n-1):
            if y == x-1:
                y = x+3
            if a[i] == 0:
                a[i] = y
                y += 1
        for t in a:
            print(t)