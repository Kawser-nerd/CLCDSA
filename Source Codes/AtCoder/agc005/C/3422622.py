n = int(input())

a = list(map(int, input().split()))

a = sorted(a)

m = a[-1]
f = 1
if m % 2 == 1:
    s = m // 2 + 1
    count = 0
    if n == 2:
        if a[0] != 1 or a[1] != 1:
            f = 0
    elif a[0] != s or a[2] == s:
        f = 0
    else:
        for i in range(n):
            if a[i] < s:
                continue
            elif a[i] == s:
                if count == 0:
                    count = 1
                else:
                    count = 0
                    s += 1
            else:
                f = 0
                break
        if count == 1:
            f = 0
else:
    s = m // 2 + 1
    count = 0
    if a[0] != s-1 or a[1] == s-1:
        f = 0
    else:
        for i in range(1, n):
            if a[i] < s:
                continue
            elif a[i] == s:
                if count == 0:
                    count = 1
                else:
                    count = 0
                    s += 1
            else:
                f = 0
                break
        if count == 1:
            f = 0
        
if f == 1:
    print('Possible')
else:
    print('Impossible')