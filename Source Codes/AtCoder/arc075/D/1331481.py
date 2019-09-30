def result(letters, number, cant_zero):
    if letters <= 1:
        if number == 0:
            return 10 ** letters
        return 0
    diff = (10 - number%10) % 10
    variants = number % 10 - cant_zero
    if number % 10 == 0:
        variants = 10 - cant_zero
    number -= diff * (10**(letters-1) - 1)
    number = abs(number // 10)
    return variants * result(letters-2, number, 0)

d = int(input())
ans = 0
for i in range(20):
    ans += result(i, d, 1)
print(ans)