n = int(input())
if n == 3:
    print("2 5 63")
elif n == 4:
    print("2 5 20 63")
elif n == 5:
    print("3 4 6 8 9")
elif n == 6:
    print("2 3 4 8 9 10")
elif n == 7:
    print("2 3 4 6 8 9 10")
else:
    ans = []
    for i in range(n // 8):
        ans += [12 * i + 2, 12 * i + 3, 12 * i + 4, 12 * i + 6, 12 * i + 8, 12 * i + 9, 12 * i + 10, 12 * i + 12]
    if n % 8 == 1:
        ans += [ans[-1] + 6]
    elif n % 8 == 2:
        ans += [ans[-1] + 4, ans[-1] + 8]
    elif n % 8 == 3:
        ans += [ans[-1] + 4, ans[-1] + 6, ans[-1] + 8]
    elif n % 8 == 4:
        ans += [ans[-1] + 2, ans[-1] + 4, ans[-1] + 8, ans[-1] + 10]
    elif n % 8 == 5:
        ans += [ans[-1] + 3, ans[-1] + 4, ans[-1] + 6, ans[-1] + 8, ans[-1] + 9]
    elif n % 8 == 6:
        ans += [ans[-1] + 2, ans[-1] + 3, ans[-1] + 4, ans[-1] + 8, ans[-1] + 9, ans[-1] + 10]
    elif n % 8 == 7:
        ans += [ans[-1] + 2, ans[-1] + 3, ans[-1] + 4, ans[-1] + 6, ans[-1] + 8, ans[-1] + 9, ans[-1] + 10]

    print(" ".join(list(map(str, ans))))