n, x = map(int, input().split())
if x == 1 or x == 2 * n - 1:
    print("No")
else:
    numli = [i for i in range(1, 2 * n)]
    displayli = [0] * (2 * n - 1)
    if n == 2:
        if x == 2:
            print("Yes")
            for i in range(3):
                print(i + 1)
        else:
            print("No")
    else:
        k = 0
        if x == 2:
            for i in range(-3, 1):
                if abs(i) % 2 == 1:
                    displayli[n + i] = x - i - 1
                    numli.remove(x - i - 1)
                else:
                    displayli[n + i] = x + i + 1
                    numli.remove(x + i + 1)
            for i in range(2 * n - 1):
                if n - 3 <= i <= n:
                    pass
                else:
                    displayli[i] = numli[k]
                    k += 1

        elif x == 2 * n - 2:
            for i in range(-2, 2):
                if abs(i) % 2 == 1:
                    displayli[n + i] = x - i - 1
                    numli.remove(x - i - 1)
                else:
                    displayli[n + i] = x + i + 1
                    numli.remove(x + i + 1)
            for i in range(2 * n - 1):
                if n - 2 <= i <= n + 1:
                    pass
                else:
                    displayli[i] = numli[k]
                    k += 1
        else:
            for i in range(-3, 2):
                if abs(i) % 2 == 1:
                    displayli[n + i] = x - i - 1
                    numli.remove(x - i - 1)
                else:
                    displayli[n + i] = x + i + 1
                    numli.remove(x + i + 1)
            for i in range(2 * n - 1):
                if n - 3 <= i <= n + 1:
                    pass
                else:
                    displayli[i] = numli[k]
                    k += 1

        print("Yes")
        for i in range(2 * n - 1):
            print(displayli[i])