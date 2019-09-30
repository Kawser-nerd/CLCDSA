#!/usr/bin/env python3
# -*- coding: utf-8 -*-

DOM_2012 = (
    0,
    31, 29, 31, 30, 31, 30,
    31, 31, 30, 31, 30, 31
)

def day_of_year(m, d):
    return sum(DOM_2012[:m]) + d-1

def main():
    assert sum(DOM_2012) == 366

    IS_HOLI = [i%7 in (0,6) for i in range(366)]

    N = int(input())
    for _ in range(N):
        m, d = map(int, input().split("/"))
        doy = day_of_year(m,d)
        if not IS_HOLI[doy]:
            IS_HOLI[doy] = True
        else:
            for i in range(doy+1, 366):
                if not IS_HOLI[i]:
                    IS_HOLI[i] = True
                    break

    ans = 0
    curr = 0
    for day in range(366):
        if IS_HOLI[day]:
            curr += 1
        else:
            if curr > 0:
                ans = max(ans, curr)
                curr = 0
    ans = max(ans, curr)

    print(ans)

if __name__ == "__main__": main()