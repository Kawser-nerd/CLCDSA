#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2014 KuoE0 <kuoe0.tw@gmail.com>
#
# Distributed under terms of the MIT license.

"""

"""

N = None
M = None
K = None

def BT(stone, inter, width, height):

    global N
    global M
    global K

    if inter >= K:
        return stone

    ret = None

    if K - inter <= 4:
        ret = stone + K - inter

    if width + 1 <= N:
        if not ret:
            ret = BT(stone + 2, inter + height / 2 + 2, width + 1, height)
        else:
            ret = min(ret, BT(stone + 2, inter + height / 2 + 2, width + 1, height))
    if height + 1 <= M:
        if not ret:
            ret = BT(stone + 2, inter + width / 2 + 2, width, height + 1)
        else:
            ret = min(ret, BT(stone + 2, inter + width / 2 + 2, width, height + 1))
    
    if width + 1 <= N and height > 3 and inter + 2 >= K:
        ret = min(ret, stone + 1)
    if height + 1 <= M and width > 3 and inter + 2 >= K:
        ret = min(ret, stone + 1)

    return ret

T = input()

for t in xrange(T):
    N, M, K = [int(x) for x in raw_input().split()]

    if N < 3 or M < 3 or K <= 4:
        print "Case #{0}: {1}".format(t + 1, K)
    else:
        print "Case #{0}: {1}".format(t + 1, BT(4, 5, 3, 3))


