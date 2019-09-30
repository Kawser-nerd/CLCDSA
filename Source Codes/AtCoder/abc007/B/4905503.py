a = str(input())

if a == 'a':
    ans = -1
    print(ans)
elif len(a) == 1:
    tmp = ord(a) - 1
    ans = chr(tmp)
    print(ans)
elif len(a) >= 2:
    ans = a[:-1]
    print(ans)