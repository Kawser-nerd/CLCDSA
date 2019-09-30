x = int(input())
res = x//11*2
if 0 < x % 11 <= 6:
    print(res + 1)
elif x % 11 > 6:
    print(res + 2)
else:
    print(res)