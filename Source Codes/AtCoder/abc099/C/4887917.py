import bisect

six_list = [6 ** i for i in range(7)]
nine_list = [9 ** i for i in range(6)]

from functools import lru_cache


@lru_cache(maxsize=1000)
def six_nine(n):
    if n < 6:
        return n
    else:
        six = six_list[bisect.bisect_right(six_list, n) - 1]
        nine = nine_list[bisect.bisect_right(nine_list, n) - 1]
        return min(n // six + six_nine(n % six), 1 + six_nine(n - nine))


if __name__ == '__main__':
    x = int(input())
    print(six_nine(x))