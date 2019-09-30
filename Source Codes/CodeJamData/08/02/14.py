#! /opt/local/bin/python
# -*- coding: utf8 -*-

from heapq import heappush, heappop

def train_count(hq):
    tmp = []
    prev = -1
    current = 0
    minimal = 0

    while hq:
        diff = heappop(hq)
        if prev == diff[0] :
            tmp[-1] += diff[1]
        else:
            tmp.append(diff[1])
        prev = diff[0]

    for val in tmp:
        current += val
        if minimal > current:
            minimal = current

    return -minimal

def main():
    for c in range(input()):
        turn = input()
        train_a_hq = []
        train_b_hq = []

        trips_a, trips_b = map(int,raw_input().split())

        for i in range(trips_a):
            dep_ab_str, arr_ab_str = map(str,raw_input().split())

            dep_ab_h, dep_ab_m = map(int,dep_ab_str.split(':'))
            arr_ab_h, arr_ab_m = map(int,arr_ab_str.split(':'))

            dep_ab = dep_ab_h * 60 + dep_ab_m
            arr_ab = arr_ab_h * 60 + arr_ab_m

            heappush(train_a_hq, [dep_ab,        -1])
            heappush(train_b_hq, [arr_ab + turn,  1])

        for i in range(trips_b):
            dep_ba_str, arr_ba_str = map(str,raw_input().split())

            dep_ba_h, dep_ba_m = map(int,dep_ba_str.split(':'))
            arr_ba_h, arr_ba_m = map(int,arr_ba_str.split(':'))

            dep_ba = dep_ba_h * 60 + dep_ba_m
            arr_ba = arr_ba_h * 60 + arr_ba_m

            heappush(train_b_hq, [dep_ba,        -1])
            heappush(train_a_hq, [arr_ba + turn,  1])

        need_a = train_count(train_a_hq)
        need_b = train_count(train_b_hq)

        print 'Case #%d: %d %d' % ( c+1, need_a, need_b )

if __name__ == '__main__':
    main()
