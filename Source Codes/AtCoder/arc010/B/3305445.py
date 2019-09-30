#!/usr/bin/env python3

import datetime

def main():
    n = int(input())
    md = []
    for i in range(n):
        m, d = map(int, input().split("/"))
        md.append((m, d))
    md = sorted(md)

    stored = 0
    streak = 0
    ma_streak = 0
    dt = datetime.datetime(2012, 1, 1) - datetime.timedelta(1)
    for i in range(366):
        dt += datetime.timedelta(1)
        is_holiday = (dt.month, dt.day) in md
        is_yasumi, stored = advance(dt, stored, is_holiday)
        if is_yasumi:
            streak += 1
            ma_streak = max(ma_streak, streak)
        else:
            streak = 0

    print(ma_streak)

def advance(today, stored, is_holiday):
    if is_weekend(today):
        stored += 1
    if is_holiday:
        stored += 1
    if stored > 0:
        is_yasumi = True
        stored -= 1
    else:
        is_yasumi = False
    return is_yasumi, stored

def is_weekend(today):
    return today.weekday() in [5, 6]

main()