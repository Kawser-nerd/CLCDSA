#!/usr/bin/env python3

import sys

max_len = 100

def gen(length, leading, sum_left):

    if length == 1:
        i = leading
        while i < 10 and i*i <= sum_left:
            yield str(i)
            i += 1
    elif length == 2:
        i = leading
        while i < 10 and 2*i*i <= sum_left:
            yield str(i)+str(i)
            i += 1
    else:
        i = leading
        while i < 10 and 2*i*i <= sum_left:
            for p in gen(length - 2, 0, sum_left - 2*i*i):
                yield str(i) + str(p) + str(i)
            i += 1

def gen_all():
    length = 1
    for length in range(1, max_len//2 + 1):
        for p in gen(length, 1, 9):
            yield p

fair_and_square = list(int(p)**2 for p in gen_all())

for case in range(int(sys.stdin.readline())):
    A,B = map(int, sys.stdin.readline().split())
    answer = sum(A <= pp <= B for pp in fair_and_square)
    print('Case #{}: {}'.format(case + 1, answer))
