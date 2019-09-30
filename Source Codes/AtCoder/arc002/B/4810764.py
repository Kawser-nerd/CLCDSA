# -*- coding: utf-8 -*-


def main():
    from datetime import datetime
    from datetime import timedelta

    ymd = input()
    fmt = '%Y/%m/%d'
    current_date = datetime.strptime(ymd, fmt)

    # See:
    # https://atcoder.jp/contests/arc002/submissions/4809566
    while True:
        year = current_date.year
        month = current_date.month
        day = current_date.day
        candidate = datetime.strftime(current_date, fmt)

        if year % (month * day) == 0 and candidate >= ymd:
            print(candidate)
            exit()

        current_date += timedelta(days=1)


if __name__ == '__main__':
    main()