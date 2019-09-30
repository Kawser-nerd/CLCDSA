#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: solve.py
# $Date: Sat Apr 16 09:23:24 2016 +0800
# $Author: jiakai <jia.kai66@gmail.com>

import collections

def solve(rows):
    cnt = collections.Counter()
    for i in rows:
        cnt.update(i)

    rst = []
    for k, v in cnt.items():
        if v % 2:
            rst.append(k)
    return ' '.join(map(str, sorted(rst)))

def main():
    nr_case = int(input())
    for case in range(nr_case):
        N = int(input())
        rows = []
        for i in range(N*2-1):
            rows.append(list(map(int, input().split())))
        print('Case #{}: {}'.format(case + 1, solve(rows)))

if __name__ == '__main__':
    main()



