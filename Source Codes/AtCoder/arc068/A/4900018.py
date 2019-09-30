x = int(input())

mod = x % 11

if mod == 0:
    print(x // 11 * 2)
elif mod <= 6:
    print(x // 11 * 2 + 1)
else:
    print(x // 11 * 2 + 2)