#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# $File: solve.py
# $Date: Sat Apr 16 09:07:35 2016 +0800
# $Author: jiakai <jia.kai66@gmail.com>

def solve(S):
    rst = S[0]
    for i in S[1:]:
        a = rst + i
        b = i + rst
        rst = max(a, b)
    return rst

def main():
    nr_case = int(input())
    for i in range(nr_case):
        print('Case #{}: {}'.format(i + 1, solve(input())))

if __name__ == '__main__':
    main()

