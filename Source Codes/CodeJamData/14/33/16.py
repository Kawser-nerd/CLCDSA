from cmath import sqrt
import math

T = int(input())
test = 1

while test <= T:
    print("Case #" + str(test) + ": ", end="")
    test += 1

    mnk = input().split()
    m = int(mnk[0])
    n = int(mnk[1])
    k = int(mnk[2])

    # make m the smaller
    if m > n:
        tmp = n
        n = m
        m = tmp

    if m <= 2:
        print(k)
        continue

    if m*n - k <= 4:
        print((m+n-4)*2 - m*n + k + 4)
        continue

    size = math.ceil(sqrt(k+4).real)

    w = 0
    if size > m:
        w = m
    else:
        w = size

    h = size - 1
    while w*h - 4 < k:
        h += 1

    ans = (w+h-4)*2

    # make h the smaller one
    if h > w:
        tmp = h
        h = w
        w = tmp

    if (w*h - 4) - k >= 2 and m > 3:
        ans -= 1

    if (w-1)*h - 3 >= k:
        ans = min((w+h-5)*2+1, ans)


    print(ans)