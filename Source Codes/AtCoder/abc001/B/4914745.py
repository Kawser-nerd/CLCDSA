m = int(input())

if m < 100:
    print('00')
elif m <= 5000:
    m //= 100
    s = list(str(m + 100))
    print(''.join(s[1:]))
elif m <= 30000:
    m //= 1000
    m += 50
    print(m)
elif m <= 70000:
    m = (m - 30000) // 5 + 80000
    print(m // 1000)
else:
    print(89)