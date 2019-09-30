a, b = list(map(int, input().split()))
if 9 - int(a/100) > int(b/100) - 1:
    print(a + 100*(9 - int(a/100)) - b)
elif 9 - int(a/100) < int(b/100) - 1:
    print(a - b + 100*(int(b/100)-1))
elif int(a/100) == 9 and int(b/100) == 1:
    if int(a/10) == 99 and int(b/10) == 10:
        num = max(9 - a % 10, b % 10)
        print(a - b + int(num))
    else:
        num2 = max(9 - int((a - 900)/10), int((b - 100)/10))
        print(a - b + int(num2*10))
else:
    print(a - b + 100 * (int(b / 100) - 1))