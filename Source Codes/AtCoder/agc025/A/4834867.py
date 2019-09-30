N = int(input())


def sum_digit(n):
    s = 0
    while n > 0:
        s += n % 10
        n //= 10
    return s


min_sum = 9 * 10
for x in range(1, N // 2 + 1):
    min_sum = min(min_sum, sum_digit(x) + sum_digit(N - x))
print(min_sum)