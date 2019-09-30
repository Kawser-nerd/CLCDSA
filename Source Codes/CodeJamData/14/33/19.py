#!/usr/bin/python
# -*- coding: utf-8 -*-

import Queue
def resoudre(n,m,k):
    if (n < m):
        return resoudre(m,n,k)
    # n >= m
    if (m <= 2):
        return k
    elif (m == 3):
        if (k < 5):
            return k
        elif (k < 8 or n == 3):
            return k-1
        elif (k < 11 or n == 4):
            return k-2
        elif (k < 14 or n == 5):
            return k-3
        elif (k < 17 or n == 6):
            return k-4
        else:
            return k-4
    elif (m == 4):
        if (k < 5):
            return k
        elif (k < 8):
            return k-1
        elif (k < 10):
            return k-2
        elif (k < 12):
            return k-3
        elif (n == 4):
            return k-4
        # grille de (4,5)
        elif (k < 14):
            return k-4
        elif (k < 16):
            return k-5
        else:
            return k-6
    print "Bug %d %d" % (n,m)
    # grille de (5,5)
    '''
    else:
        if (k < 5):
            return k
        elif (k < 8):
            return k-1
        elif (k < 10):
            return k-2
        elif (k < 12):
            return k-3
        elif (k < 14):
            return k-4
        elif (k < 16):
            return k-5
        elif (k < 17):
            return k-6
        elif (k < 19):
            return k-7
        elif (k < 21):
            return k-8
        else:
            return k-9
    '''



nbcases = int(raw_input())

for case in xrange(1,nbcases+1):
    [n,m,k] =  [eval (n) for n in raw_input().strip().split(" ")]
    print "Case #%d: %d" % (case,resoudre(n,m,k))

