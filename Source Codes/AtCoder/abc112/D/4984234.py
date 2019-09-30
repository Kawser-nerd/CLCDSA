import math

n, m = map(int, input().split())


def get_divisors(n):
    ret = []
    for i in range(1, int(math.sqrt(n)) + 1):
        if n % i == 0:
            ret.append(i)
            if n // i != i:
                ret.append(n // i)
    return ret


# m ???????
divs = get_divisors(m)
divs.sort(reverse=True)

for d in divs:
    if d * n <= m:
        print(d)
        break