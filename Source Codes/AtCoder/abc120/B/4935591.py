a, b, k = [int(s) for s in input().split()]


def f(s, l, k):
    numbers = []
    for i in range(1, s + 1):
        if s % i == 0 and l % i == 0:
            numbers.append(i)

    print(numbers[-k])


if a > b:
    f(b, a, k)
else:
    f(a, b, k)