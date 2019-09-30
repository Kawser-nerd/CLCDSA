import collections

n = int(input())
a = list(map(int, input().split()))
ac = collections.Counter(a)
if n % 2:
    if ac[0] != 1:
        print(0)
        exit()
    for i in ac:
        if i == 0:
            continue
        if ac[i] != 2:
            print(0)
            exit()
else:
    if ac[1] != 2:
        print(0)
        exit()
    for i in ac:
        if i == 1:
            continue
        if ac[i] != 2:
            print(0)
            exit()
mod = 10 ** 9 + 7
print((2 ** (n // 2)) % mod)