# -*- coding: utf-8 -*-


def is_leap(year):
    if year % 400 == 0:
        return True
    elif year % 100 == 0:
        return False
    elif year % 4 == 0:
        return True
    else:
        return False


def main():
    from datetime import datetime

    ymd = input()
    ymd_mod = list(map(int, ymd.split('/')))
    days = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

    for year in range(ymd_mod[0], 3000):
        for month, day in enumerate(days, 1):
            for d in range(1, day + 1):
                if is_leap(year) and month == 2 and d == 29:
                    candidate = datetime(year, month, d).strftime('%Y/%m/%d')

                    if year % (month * d) == 0 and candidate >= ymd:
                        print(candidate)
                        exit()
                elif not is_leap(year) and month == 2 and d == 29:
                    pass
                else:
                    candidate = datetime(year, month, d).strftime('%Y/%m/%d')

                    if year % (month * d) == 0 and candidate >= ymd:
                        print(candidate)
                        exit()

    print('3000/01/01')


if __name__ == '__main__':
    main()